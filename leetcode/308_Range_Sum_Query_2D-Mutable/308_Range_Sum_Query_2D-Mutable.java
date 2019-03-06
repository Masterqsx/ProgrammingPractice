class NumMatrix {
    private class Node {
        public int start;
        public int end;
        public int sum;
        public Node left;
        public Node right;
        public Node(int start, int end, int sum) {
            this.start = start;
            this.end = end;
            this.sum = sum;
        }
    }
    
    private Node root;
    
    private int rL;
    
    private int cL;
    
    private Node build(int s, int e, int[][] matrix) {
        Node cur = new Node(s, e, 0);
        if (s < e) {
            int mid = s + (e - s) / 2;
            cur.left = build(s, mid, matrix);
            cur.right = build(mid + 1, e, matrix);
            cur.sum = cur.left.sum + cur.right.sum;
        } else {
            int row = s / cL;
            int col = s % cL;
            cur.sum = matrix[row][col];
        }
        return cur;
    }

    public NumMatrix(int[][] matrix) {
        rL = matrix.length;
        if (rL > 0) cL = matrix[0].length;
        if (rL > 0 && cL > 0) root = build(0, rL * cL - 1, matrix);
    }
    
    private void updateHelper(Node n, int index, int val) {
        if (n.start == index && n.end == n.start) n.sum = val;
        else if (n.start <= index && n.end >= index) {
            int mid = n.start + (n.end - n.start) / 2;
            if (mid >= index) updateHelper(n.left, index, val);
            else updateHelper(n.right, index, val);
            n.sum = n.left.sum + n.right.sum;
        }
    }
    
    public void update(int row, int col, int val) {
        int index = row * cL + col;
        updateHelper(root, index, val);
    }
    
    private int query(Node n, int start, int end) {
        if (n.start <= end && start <= n.end) { //make sure it has intersection
            if (start <= n.start && end >= n.end) return n.sum;
            else return query(n.left, start, end) + query(n.right, start, end);
        } else return 0;
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = 0;
        for (int i = row1; i <= row2; i++) {
            int start = i * cL + col1;
            int end = i * cL + col2;
            res += query(root, start, end);
        }
        return res;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
