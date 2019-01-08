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
    public void recursive(TreeNode root, int[] maxDepth, int curDepth, List<TreeNode> maxPath, List<TreeNode> path) {
        path.add(root);
        if (root.left == null && root.right == null) {
            if (curDepth > maxDepth[0]) {
                maxPath.clear();
                for (TreeNode i : path) maxPath.add(i);
                maxDepth[0] = curDepth;
            }
            else if (curDepth == maxDepth[0]) {
                int firstIncommon = 0;
                for (; firstIncommon < maxPath.size(); firstIncommon++) {
                    if (maxPath.get(firstIncommon).val != path.get(firstIncommon).val) break;
                }
                maxPath.subList(firstIncommon, maxPath.size()).clear();
            }
        }
        else {
            if (root.left != null) recursive(root.left, maxDepth, curDepth + 1, maxPath, path);
            if (root.right != null) recursive(root.right, maxDepth, curDepth + 1, maxPath, path);
        }
        
        path.remove(path.size() - 1);
    }
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        List<TreeNode> path = new ArrayList<>();
        List<TreeNode> maxPath = new ArrayList<>();
        int[] maxDepth = new int[1];
        recursive(root, maxDepth, 1, maxPath, path);
        return maxPath.get(maxPath.size() - 1);
    }
}
