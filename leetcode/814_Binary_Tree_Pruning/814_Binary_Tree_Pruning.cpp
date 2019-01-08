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
    bool markDelete(TreeNode* root) {
        if (root == NULL) return false;
        bool left = markDelete(root->left);
        bool right = markDelete(root->right);
        if (left == false) root->left = NULL;
        if (right == false) root->right = NULL;
        if (left == false && right == false && root->val == 0) return false;
        else return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool rootRes = markDelete(root);
        if (!rootRes) return NULL;
        else return root;
    }
};
