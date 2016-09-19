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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPathSum_helper(root);
        return maxSum;
    }
    int maxPathSum_helper(TreeNode* root) {
        if (root == NULL) return 0;
        int l = maxPathSum_helper(root->left);
        int r = maxPathSum_helper(root->right);
        maxSum = max(maxSum, max(l+r+root->val, max(l+root->val, max(r+root->val, root->val))));
        return max(l+root->val, max(r+root->val, root->val));
    }
};
