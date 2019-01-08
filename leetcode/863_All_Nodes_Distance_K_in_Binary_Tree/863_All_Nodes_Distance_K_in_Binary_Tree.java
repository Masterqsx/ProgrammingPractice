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
    public int searchTarget(TreeNode root, TreeNode target, Map<TreeNode, Integer> distance) {
        if (root == null) return -1;
        if (root.val == target.val) {
            distance.put(root, 0);
            return 0;
        }
        int left = searchTarget(root.left, target, distance);
        int right = searchTarget(root.right, target, distance);
        if (left == -1 && right == -1) return -1;
        distance.put(root, Integer.max(left, right) + 1);
        return Integer.max(left, right) + 1;
    }
    public void searchFixedDis(TreeNode root, TreeNode parent, int K, Map<TreeNode, Integer> distance) {
        if (root == null) return;
        int curDis = -1;
        if (distance.containsKey(root)) curDis = distance.get(root);
        else {    
            curDis = distance.get(parent) + 1;
            distance.put(root, curDis);
        }
        searchFixedDis(root.left, root, K, distance);
        searchFixedDis(root.right, root, K, distance);
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        Map<TreeNode, Integer> dis = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        searchTarget(root, target, dis);
        searchFixedDis(root, null, K, dis);
        for (Map.Entry<TreeNode, Integer> entry : dis.entrySet()) {
            if (entry.getValue() == K) res.add(entry.getKey().val);
        }
        return res;
    }
}
