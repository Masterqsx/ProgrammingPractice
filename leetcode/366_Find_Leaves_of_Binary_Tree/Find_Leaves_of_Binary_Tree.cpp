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
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        postorder(root);
        return res;
    }
    int postorder(TreeNode* root) {
        if (root == NULL) return -1;
        int l = postorder(root->left);
        int r = postorder(root->right);
        int re = max(l, r)+1;
        if (res.size() <= re) res.push_back(vector<int>({root->val}));
        else res[re].push_back(root->val);
        return re;
    }
};
