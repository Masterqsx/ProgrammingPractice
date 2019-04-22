/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int res = 0;
    public int maxAncestorDiff(TreeNode root) {
        dfsMax(root);
        dfsMin(root);
        return res;
    }
    public int dfsMax(TreeNode root) {
        if (root.left == null && root.right == null) return root.val;
        int temp = root.val;
        if (root.left != null) temp = dfsMax(root.left);
        if (root.right != null) temp = Math.max(temp, dfsMax(root.right));
        res = Math.max(res, Math.abs(temp - root.val));
        return Math.max(temp, root.val);
    }
    public int dfsMin(TreeNode root) {
        if (root.left == null && root.right == null) return root.val;
        int temp = root.val;
        if (root.left != null) temp = dfsMin(root.left);
        if (root.right != null) temp = Math.min(temp, dfsMin(root.right));
        res = Math.max(res, Math.abs(temp - root.val));
        return Math.min(temp, root.val);
    }
}
