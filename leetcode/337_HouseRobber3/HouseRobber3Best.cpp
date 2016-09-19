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
    int rob(TreeNode* root) {
        vector<int> re;
        re=rob_recursive(root);
        return re[0];
    }
    
    vector<int> rob_recursive(TreeNode* root){
        vector<int> re=vector<int>(2,0);
        if(root==NULL) return re ;
        vector<int> l=rob_recursive(root->left);
        vector<int> r=rob_recursive(root->right);
        re[0]=(max(l[0]+r[0],root->val+l[1]+r[1]));
        re[1]=(l[0]+r[0]);
        return re;
    }
};