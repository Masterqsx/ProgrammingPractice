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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int l_hi = 0, r_hi = 0;
        height(root->left, 0, l_hi);
        height(root->right, 0, r_hi);
        if (abs(l_hi-r_hi) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    void height(TreeNode* root, int level, int& hi){
        if (root == NULL){
            hi = max(level, hi);
            return;
        }
        height(root->left, level+1, hi);
        height(root->right, level+1, hi);
    }
};
