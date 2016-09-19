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
    TreeNode* pre = NULL;
    TreeNode* re_pre = NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root, p);
        return re_pre;
    }
    void inorder(TreeNode* root, TreeNode* p){
        if (root == NULL) return;
        inorder(root->left, p);
        if (pre != NULL && p->val == pre->val) {
            re_pre = root;
        }
        pre = root;
        inorder(root->right, p);
    }
};
