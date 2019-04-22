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
    public int getNextNum(String str, int i) {
        while (i < str.length()) {
            if ((str.charAt(i) - '0' >= 0) && (str.charAt(i) - '0' < 10)) return i;
            i++;
        }
        return i;
    }
    public int getNextDash(String str, int i) {
        while (i < str.length()) {
            if (str.charAt(i) == '-') return i;
            i++;
        }
        return i;
    }
    public TreeNode recoverFromPreorder(String S) {
        TreeNode[] path = new TreeNode[1000];
        int idx = getNextDash(S, 0);
        TreeNode root = new TreeNode(Integer.parseInt(S.substring(0, idx)));
        path[0] = root;
        int cur = 0;
        while(idx < S.length()) {
            int nex = getNextNum(S, idx);
            int hi = nex - idx;
            while (cur >= 0 && (hi - cur) != 1) {
                path[cur] = null;
                cur--;
            }
            idx = nex;
            nex = getNextDash(S, idx);
            TreeNode temp = new TreeNode(Integer.parseInt(S.substring(idx, nex)));
            if (path[cur].left == null) path[cur].left = temp;
            else path[cur].right = temp;
            path[++cur] = temp;
            idx = nex;
        }
        return root;
    }
}
