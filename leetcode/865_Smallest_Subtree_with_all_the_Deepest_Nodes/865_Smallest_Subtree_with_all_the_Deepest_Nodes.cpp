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
    void dfs(TreeNode* root, int& maxDepth, int curDepth) {
        if (root == NULL) return;
        maxDepth = max(maxDepth, curDepth);
        dfs(root->left, maxDepth, curDepth + 1);
        dfs(root->right, maxDepth, curDepth + 1);
    }
    TreeNode* findLca(TreeNode* root, int maxDepth, int curDepth) {
        if (root == NULL) return NULL;
        if (curDepth == maxDepth) return root;
        TreeNode* left = findLca(root->left, maxDepth, curDepth + 1);
        TreeNode* right = findLca(root->right, maxDepth, curDepth + 1);
        if (left != NULL && right != NULL) return root;
        if (left != NULL) return left;
        if (right != NULL) return right;
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = 0;
        dfs(root, maxDepth, 1);
        return findLca(root, maxDepth, 1);
    }
};
