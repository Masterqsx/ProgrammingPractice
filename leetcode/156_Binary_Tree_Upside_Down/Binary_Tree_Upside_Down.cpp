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
    TreeNode* new_root = NULL;
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) return NULL;
        inorder(root);
        root->left = NULL;
        root->right = NULL;
        return new_root;
    }
    TreeNode* inorder(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* pre = inorder(root->left);
        if (pre != NULL) {
            pre->right = root;
            pre->left = root->right;
        }
        else new_root = root;
        return root;
    }
};
