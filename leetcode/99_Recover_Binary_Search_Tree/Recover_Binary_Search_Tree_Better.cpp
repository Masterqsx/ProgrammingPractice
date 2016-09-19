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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    bool flag = true;
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        inorder(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
        if (pre != NULL && pre->val > root->val){
            if (flag) {
                flag = false;
                first = pre;
                second = root;//potential replace point
            }
            else second = root;
        }
        pre = root;
        inorder(root->right);
    }
};
