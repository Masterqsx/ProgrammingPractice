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
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        inorder(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
    void inorder(TreeNode* root){
        while (root != NULL){
            if (root->left != NULL){
                TreeNode* leftmost = root->left;
                while (leftmost->right != NULL && leftmost->right != root) leftmost = leftmost->right;
                if (leftmost->right == root) {
                    leftmost->right = NULL;
                    if (pre != NULL && pre->val > root->val){
                        if (!first) {
                            first = pre;
                            second = root;
                        }
                        else second = root;
                    }
                    pre = root;
                    root = root->right;
                }
                else {
                    leftmost->right = root;
                    root = root->left;
                }
            }
            else {
                if (pre != NULL && pre->val > root->val){
                    if (!first) {
                        first = pre;
                        second = root;
                    }
                    else second = root;
                }
                pre = root;
                root = root->right;
            }
        }
    }
};
