package algorithm.segment_tree;

public class MySegmentTree {
    /** important property: if it is not leaf node, it will have two valid children **/
    public class Node {
        public int start;
        public int end;
        public int max;
        public int mark;
        public Node left;
        public Node right;
        public Node(int start, int end, int max) {
            this.start = start;
            this.end = end;
            this.max = max;
        }
    }

    private int sz;

    private Node root;

    public MySegmentTree(int sz) {
        this.sz = sz;
        root = build(0, sz - 1);
    }

    public Node build(int start, int end) {
        Node n = new Node(start, end, 0);
        if (start == end) return n;
        int mid = start + (end - start) / 2;
        n.left = build(start, mid);
        n.right = build(mid + 1, end);
        return n;
    }

    /** any operation need to traverse lower level need pushDown before **/
    //The node with tag will be updated value during pushDown
    private void pushDown(Node n) {
        if (n.mark != 0) {
            if (n.left != null) {
                n.left.mark += n.mark;
                n.left.max += n.mark;
            }
            if (n.right != null) {
                n.right.mark += n.mark;
                n.right.max += n.mark;
            }
            n.mark = 0;
        }
    }

    public int query(int start, int end) {
        if (start < 0 || start > end || end >= sz) return Integer.MIN_VALUE;
        return queryHelper(root, start, end);
    }

    /** divided into 4 situations **/
    private int queryHelper(Node n, int start, int end) {
        if (start <= n.end && n.start <= end) {// if query range has intersection, we do not need to worry null exception since it will be covered by the next condition
            if (start <= n.start && end >= n.end) return n.max; //if query range contain current range
            else {// if query range is partially connect
                pushDown(n);
                return Math.max(queryHelper(n.left, start, end), queryHelper(n.right, start, end));
            }
        }
        else return Integer.MIN_VALUE;
    }

    /** update only one single value **/
    public void updateSingle(int index, int value) {
        if (index >= 0 && index < sz) updateSingleHelper(root, index, value);
    }

    public int updateSingleHelper(Node n, int index, int value) {
        if (n.start == n.end && n.end == index) { // since leaf node has null left and right, do this to make sure NULL pointer won't happen
            n.max = value;
            return value;
        }
        else if (index >= n.start && index <= n.end) {
            int mid = n.start + (n.end - n.start) / 2;
            pushDown(n);
            if (index > mid) n.max = Math.max(n.max, updateSingleHelper(n.right, index, value));
            else n.max = Math.max(n.max, updateSingleHelper(n.left, index, value));
        }
        return n.max;
    }

    /** update a range with value change **/
    public void update(int start, int end, int value) {
        if (start >= 0 && start <= end && end < sz) updateHelper(root, start, end, value);
    }

    public void updateHelper(Node n, int start, int end, int value) {
        if (n == null || n.start > end || n.end < start) return;
        if (start <= n.start && end >= n.end) {
            n.max += value;
            n.mark += value;
            return;
        }
        pushDown(n);
        updateHelper(n.left, start, end, value);
        updateHelper(n.right, start, end, value);
        n.max = Math.max(n.left.max, n.right.max);
    }


}
