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
    public void dfs(TreeNode root, int depth, List<List<TreeNode>> levels) {
        if (root == null) return;
        if (depth >= levels.size()) {
            levels.add(new ArrayList<TreeNode>());
        }
        levels.get(depth).add(root);
        dfs(root.left, depth + 1, levels);
        dfs(root.right, depth + 1, levels);
    }
    public int findBottomLeftValue(TreeNode root) {
        List<List<TreeNode>> levels = new ArrayList<>();
        dfs(root, 0, levels);
        return levels.get(levels.size() - 1).get(0).val;
    }
}
