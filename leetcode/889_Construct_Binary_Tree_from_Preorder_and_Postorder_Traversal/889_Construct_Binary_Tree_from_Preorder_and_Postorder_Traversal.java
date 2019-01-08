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
    public TreeNode recursive(ArrayList<Integer> pre, ArrayList<Integer> post) {
        if (pre.size() == 0) return null;
        if (pre.size() == 1) return new TreeNode(pre.get(0));
        int left = pre.get(1);
        int right = post.get(post.size() - 2);
        TreeNode root = new TreeNode(pre.get(0));
        if (left == right) {
            root.left = recursive(new ArrayList<Integer>(pre.subList(1, pre.size())), new ArrayList<Integer>(post.subList(0, post.size() - 1)));
            return root;
        }
        int leftIndex = post.size() - 1;
        for (;leftIndex >= 0; leftIndex--) {
            if (post.get(leftIndex) == left) break;
        }
        int rightIndex = 0;
        for (;rightIndex < pre.size(); rightIndex++) {
            if (pre.get(rightIndex) == right) break;
        }
        root.left = recursive(new ArrayList<Integer>(pre.subList(1, rightIndex)), new ArrayList<Integer>(post.subList(0, leftIndex + 1)));
        root.right = recursive(new ArrayList<Integer>(pre.subList(rightIndex, pre.size())), new ArrayList<Integer>(post.subList(leftIndex + 1, post.size() - 1)));
        return root;
    }
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        ArrayList<Integer> pr = new ArrayList<>();
        ArrayList<Integer> po = new ArrayList<>();
        for (int i : pre) pr.add(i);
        for (int i : post) po.add(i);
        return recursive(pr, po);
    }
}
