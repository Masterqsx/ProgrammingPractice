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
    void count(TreeNode* root, int target, int& res, int sum) {
        if (root == NULL) return;
        if (sum + root->val == target) res++;
        count(root->left, target, res, sum + root->val);
        count(root->right, target, res, sum + root->val);
    }
    void dfs(TreeNode* root, int target, int& res) {
        if (root == NULL) return;
        int co = 0;
        count(root, target, co, 0);
        res += co;
        dfs(root->left, target, res);
        dfs(root->right, target, res);
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        dfs(root, sum, res);
        return res;
    }
};
