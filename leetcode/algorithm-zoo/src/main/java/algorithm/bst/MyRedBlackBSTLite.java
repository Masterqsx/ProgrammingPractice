package algorithm.bst;

public class MyRedBlackBSTLite {
    //This is the Red-Black BST can only search and add nodes

    private static final boolean RED = true;
    private static final boolean BLACK = false;
    public Node root;

    private class Node {
        int val;
        Node left;
        Node right;
        boolean color;
        public Node(int val, boolean color) { this.val = val; this.color = color; }
    }

    private Node rotateLeft(Node root) {

        Node nRoot = root.right;
        root.right = nRoot.left;
        nRoot.left = root;

        root.color = RED;
        nRoot.color = root.color;

        return nRoot;
    }

    private Node rotateRight(Node root) {

        Node nRoot = root.left;
        root.left = nRoot.right;
        nRoot.right = root;

        root.color = RED;
        nRoot.color = root.color;

        return nRoot;
    }

    private void flipColor(Node root) {
        root.color = RED;
        root.left.color = BLACK;
        root.right.color = BLACK;
    }

    private boolean isRed(Node root) {
        if (root == null) return false;
        return root.color == RED;
    }

    public void insert(int val) {
        root = insert(root, val);
        root.color = BLACK;
    }

    private Node insert(Node root, int val) {
        //new node initialized as RED at the bottom
        // since we can not increase the height of the tree without balancing (pop 4-node up)
        if (root == null) return new Node(val, RED);

        if (root.val > val) root.left = insert(root.left, val);
        else if (root.val < val) root.right = insert(root.right, val);
        else root.val = val;

        if (!isRed(root.left) && isRed(root.right)) rotateLeft(root);
        if (isRed(root.left) && isRed(root.left.left)) rotateRight(root);
        if (isRed(root.left) && isRed(root.right)) flipColor(root);

        return root;
    }

    //Code for testing purpose
    public boolean isBalance() {
        return isBalanced(root, -1, 0);
    }

    private boolean isBalanced(Node root, int height, int cur) {
        if (root == null) {
            if (height == -1) height = cur;
            return height == cur;
        }
        int next = cur;
        if (root.color == BLACK) next++;
        return isBalanced(root.left, height, next) && isBalanced(root.right, height, next);
    }

    public boolean isBST() {
        return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isBST(Node root, int min, int max) {
        if (root == null) return true;
        if (root.val < max && root.val > min) return isBST(root.left, min, root.val) && isBST(root.right, root.val, max);
        else return false;
    }

}
