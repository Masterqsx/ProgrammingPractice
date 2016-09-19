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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > re;
        vector<int> com;
        recursive(re,com,sum,root);
        return re;
    }
    void recursive(vector<vector<int> >& re,vector<int>& com,int sum,TreeNode* root){
        if(root==NULL)
            return;
        com.push_back(root->val);
        if((sum-root->val==0)&&(root->left==NULL)&&(root->right==NULL){
            re.push_back(com);//very import condition, if integrate this with root==NULL, will cause two answer push into the result vector
        }
        else{
            recursive(re,com,sum-root->val,root->left);
            recursive(re,com,sum-root->val,root->right);
        }
        com.pop_back();
        return;
    }
};