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
    int max_height = 0;
    int maxDepth(TreeNode* root) {
        maxDepth_helper(root, 0);
        return max_height;
    }
    void maxDepth_helper(TreeNode* root, int level){
        if (root == NULL){
            max_height = max(max_height, level);
            return;
        }
        maxDepth_helper(root->left, level+1);
        maxDepth_helper(root->right, level+1);
    }
};
