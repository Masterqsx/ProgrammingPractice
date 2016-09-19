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
    int n = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        inorder(root);
        return n;
    }
    bool inorder(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            n++;
            return true;
        }
        bool flag = true;
        if (root->left != NULL) {
            if (inorder(root->left) && root->val == root->left->val) ;
            else flag = false;
        }
        if (root->right != NULL) {
            if (inorder(root->right) && root->val == root->right->val) ;
            else flag = false;
        }
        if (flag) n++;
        return flag;
    }
};
