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
    void dfsHeight(TreeNode* root, int h, int& maxH) {
        if (root == NULL) return;
        maxH = max(maxH, h);
        dfsHeight(root->left, h + 1, maxH);
        dfsHeight(root->right, h + 1, maxH);
    }
    void dfsFill(TreeNode* root, int h, int start, int range, vector<vector<string>>& res) {
        if (root == NULL) return;
        res[h][start + range / 2] = to_string(root->val);
        dfsFill(root->left, h + 1, start, range / 2, res);
        dfsFill(root->right, h + 1, start + range / 2 + 1, range / 2, res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = 0;
        dfsHeight(root, 0, height);
        int n = pow(2, height + 1) - 1;
        int m = height + 1;
        vector<vector<string>> res(m, vector<string>(n, string()));
        dfsFill(root, 0, 0, n, res);
        return res;
    }
};
