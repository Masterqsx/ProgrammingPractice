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
    public TreeNode dfs(int[] nums, int start, int end) {
        if (end <= start) return null;
        int maxIndex = start;
        for (int i = start; i < end; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        TreeNode root = new TreeNode(nums[maxIndex]);
        root.left = dfs(nums, start, maxIndex);
        root.right = dfs(nums, maxIndex + 1, end);
        return root;
    }
    
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return dfs(nums, 0, nums.length);
    }
}
