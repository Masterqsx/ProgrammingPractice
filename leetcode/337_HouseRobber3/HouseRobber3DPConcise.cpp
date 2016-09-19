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
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        if(find(root,sum)) return sum;
        int ll=0,lr=0,rl=0,rr=0;
        if(root->left!=NULL){
            ll=rob(root->left->left);
            lr=rob(root->left->right);
        }
        if(root->right!=NULL){
            rl=rob(root->right->left);
            rr=rob(root->right->right);
        }
        sum=max(root->val+ll+lr+rl+rr,rob(root->right)+rob(root->left));
        dp[root]=sum;
        return sum;
    }
    bool find(TreeNode* target,int& re){
        if(target==NULL){
            re=0;
            return true;
        }
        unordered_map<TreeNode*,int>::iterator it;
        it=dp.find(target);
        if(it==dp.end()) return false;
        else{
            re=it->second;
            return true;
        }
    }
};