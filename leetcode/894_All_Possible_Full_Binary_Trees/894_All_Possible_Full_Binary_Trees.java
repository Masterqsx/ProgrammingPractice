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
    public List<TreeNode> allPossibleFBT(int N) {
        List<List<TreeNode>> rootIteration = new ArrayList<>();
        if (N > 0) {
            rootIteration.add(new ArrayList<TreeNode>());
            rootIteration.get(0).add(new TreeNode(0));
        }
        if (N > 1) rootIteration.add(new ArrayList<TreeNode>());
        for (int sz = 2; sz <= N; sz++) {
            List<TreeNode> currentPossible = new ArrayList<TreeNode>();
            for (int leftSz = 1; leftSz <= sz - 1; leftSz++) {
                List<TreeNode> leftPossible = rootIteration.get(leftSz - 1);
                List<TreeNode> rightPossible = rootIteration.get(sz - leftSz - 1);
                if (leftPossible.size() > 0 && rightPossible.size() > 0) {             
                    for (TreeNode leftRoot : leftPossible) {
                        for (TreeNode rightRoot : rightPossible) {
                            TreeNode currentRoot = new TreeNode(0);
                            currentRoot.left = leftRoot;
                            currentRoot.right = rightRoot;
                            currentPossible.add(currentRoot);
                        }
                    }
                }
            }
            rootIteration.add(currentPossible);
        }
        return rootIteration.get(N - 1);
    }
}
