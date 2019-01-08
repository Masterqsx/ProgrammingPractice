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
    public void dfs(TreeNode root, int targetD, int d, int v) {
        if (root == null) return;
        if (d == targetD - 1) {
            TreeNode l = new TreeNode(v);
            TreeNode r = new TreeNode(v);
            l.left = root.left;
            r.right = root.right;
            root.left = l;
            root.right = r;
        }
        else {
            dfs(root.left, targetD, d + 1, v);
            dfs(root.right, targetD, d + 1, v);
        }
    }
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        TreeNode res = root;
        if (d == 1) {
            res = new TreeNode(v);
            res.left = root;
        }
        else dfs(root, d, 1, v);
        return res;
    }
}
