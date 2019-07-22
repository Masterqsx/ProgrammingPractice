package algorithm.hoffman_tree;

import java.util.PriorityQueue;

public class MyHoffmanTree {
    public static class Node {
        public Node left;
        public Node right;
        public int val;
        public int idx;
        public Node(int val) {this.val = val;}
        public Node(int val, int idx) {this.val = val;this.idx = idx;}
    }

    Node root;

    private void buildTree(int[] arr) {
        PriorityQueue<Node> pq = new PriorityQueue<>((l, r) -> l.val - r.val);
        for (int i = 0; i < arr.length; i++) pq.add(new Node(arr[i], i));
        while (pq.size() > 1) {
            Node n1 = pq.poll();
            Node n2 = pq.poll();
            Node n = new Node(n1.val + n2.val, -1);
            n.left = n1.val > n2.val ? n2 : n1;
            n.right = n1.val > n2.val ? n1 : n2;
            pq.add(n);
        }
        if (pq.size() > 0) root = pq.poll();
    }

    public String[] getBinaryCode(int[] arr) {
        String[] res = new String[arr.length];
        buildTree(arr);
        dfs(res, root, new StringBuffer());

        return res;
    }

    private void dfs(String[] res, Node root, StringBuffer cur) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            res[root.idx] = cur.toString();
        } else {
            if (root.left != null) {
                cur.append('0');
                dfs(res, root.left, cur);
                cur.deleteCharAt(cur.length() - 1);
            }
            if (root.right != null) {
                cur.append('1');
                dfs(res, root.right, cur);
                cur.deleteCharAt(cur.length() - 1);
            }
        }
    }
}
