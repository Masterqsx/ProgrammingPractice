/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    class state {
    public:
        bool st = true;
        int hi = 0;
        state (bool i_st, int i_hi): st(i_st), hi(i_hi) {}
    };
    bool isBalanced(TreeNode* root) {
        state res = isBalanced_helper(root);
        return res.st;
    }
    state isBalanced_helper(TreeNode* root){
        if (root == NULL) return state(true, 0);
        state l = isBalanced_helper(root->left);
        state r = isBalanced_helper(root->right);
        if (!(l.st) || !(r.st) || abs(l.hi - r.hi) > 1) return state(false, 0);
        return state(true, max(l.hi, r.hi)+1);
    }
};
