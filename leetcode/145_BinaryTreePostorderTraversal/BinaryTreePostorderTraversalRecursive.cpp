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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        traversal(re,root);
        return re;
    }
    void traversal(vector<int>& re, TreeNode* root){
        if(root==NULL) return;
        traversal(re,root->left);
        traversal(re,root->right);
        re.push_back(root->val);
    }
};