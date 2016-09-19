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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        if(root==NULL) return re;
        traversal(root,re);
        return re;
    }
    void traversal(TreeNode* root,vector<int>& re){
        if(root->left!=NULL)
            traversal(root->left,re);
        re.push_back(root->val);
        if(root->right!=NULL)
            traversal(root->right,re);
    }
};