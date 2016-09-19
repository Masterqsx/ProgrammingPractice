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
    int max_l = 1;
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        inorder(root, 1);
        return max_l;
    }
    void inorder(TreeNode* root, int l) {
        if (root->left != NULL) {
            if (root->left->val - root->val == 1) {
                max_l = max(max_l, l+1);
                inorder(root->left, l+1);
            }
            else inorder(root->left, 1);
        }
        if (root->right != NULL) {
            if (root->right->val - root->val == 1) {
                max_l = max(max_l, l+1);
                inorder(root->right, l+1);
            }
            else inorder(root->right, 1);
        }
    }
};
