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
    public class TreeNodeIndex {
        public TreeNode node;
        public int index;
        public int level;
        public TreeNodeIndex() {}
        public TreeNodeIndex(TreeNode n, int i, int l) {node = n; index = i; level = l;}
    }
    public int widthOfBinaryTree(TreeNode root) {
        Queue<TreeNodeIndex> q = new LinkedList<>();
        int maxWidth = 0;
        int startIndex = 0;
        int endIndex = 0;
        int curLevel = 0;
        if (root != null) q.add(new TreeNodeIndex(root, 0, 0));
        while (q.peek() != null) {
            TreeNodeIndex cur = q.poll();
            if (cur.level > curLevel) {
                maxWidth = Integer.max(endIndex - startIndex + 1, maxWidth);
                startIndex = cur.index;
                endIndex = cur.index;
                curLevel = cur.level;
            }
            else endIndex = cur.index;
            
            if (cur.node.left != null) {
                q.add(new TreeNodeIndex(cur.node.left, cur.index * 2, cur.level + 1));
            }
            if (cur.node.right != null) {
                q.add(new TreeNodeIndex(cur.node.right, cur.index * 2 + 1, cur.level + 1));
            }
        }
        maxWidth = Integer.max(endIndex - startIndex + 1, maxWidth);
        
        return maxWidth;
    }
}
