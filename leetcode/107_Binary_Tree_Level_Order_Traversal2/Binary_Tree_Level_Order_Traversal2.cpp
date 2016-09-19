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
    vector<vector<int>> order;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        reverse(order.begin(), order.end());
        return order;
    }
    void dfs(TreeNode* root, int level){
        if (root == NULL) return;
        if (order.size() <= level) order.push_back(vector<int>({root->val}));
        else order[level].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
};
