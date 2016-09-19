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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        recursive(re,0,root);
        return re;
    }
    void recursive(vector<int>& re,int level,TreeNode* root){
        if(root==NULL) return;
        if(re.size()<=level){
            re.push_back(root->val);
        }
        recursive(re,level+1,root->right);
        recursive(re,level+1,root->left);
    }
};