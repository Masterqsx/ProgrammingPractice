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
    private int sumAll = 0;
    private int sumPast = 0;
    public void dfs(TreeNode cur) {
        if (cur == null) return;
        sumAll += cur.val;
        dfs(cur.left);
        dfs(cur.right);
    }
    public void dfsModify(TreeNode cur) {
        if (cur == null) return;
        dfsModify(cur.left);
        sumPast += cur.val;
        cur.val = sumAll - sumPast + cur.val;
        dfsModify(cur.right);
    }
    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        dfsModify(root);
        return root;
    }
}
