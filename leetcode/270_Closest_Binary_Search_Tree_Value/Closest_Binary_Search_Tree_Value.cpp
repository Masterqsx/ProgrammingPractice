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
    double close_t = 0;
    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return 0;
        close_t = root->val;
        inorder(root, target);
        return close_t;
    }
    void inorder(TreeNode* root, double target) {
        if (root == NULL) return;
        if (abs(target-root->val) < abs(target-close_t)) close_t = root->val;
        if (target > root->val) inorder(root->right, target);
        else if (target < root->val) inorder(root->left, target);
    }
};
