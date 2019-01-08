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
    void dfs(TreeNode* root, vector<int>& maxVector, int depth) {
        if (root == NULL) return;
        if (depth >= maxVector.size()) {
            maxVector.push_back(root->val);
        }
        else {
            maxVector[depth] = max(maxVector[depth], root->val);
        }
        dfs(root->left, maxVector, depth + 1);
        dfs(root->right, maxVector, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};
