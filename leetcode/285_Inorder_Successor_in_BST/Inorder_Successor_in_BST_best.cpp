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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        TreeNode* next = NULL;
        TreeNode* cur = root;
        while (cur != NULL) {
            if (p->val < cur->val) {
                next = cur;
                cur = cur->left;
            } else cur = cur->right;
        }
   
        return next;
    }
};
