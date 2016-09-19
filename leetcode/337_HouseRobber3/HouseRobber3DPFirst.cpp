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
        int ll=0,lr=0,rl=0,rr=0,l=0,r=0;
        if(root->left!=NULL){
            if(!find(root->left->left,ll)){
                ll=rob(root->left->left);
                add(root->left->left,ll);
            }
            if(!find(root->left->right,lr)){
                lr=rob(root->left->right);
                add(root->left->right,lr);
            }
            if(!find(root->left,l)){
                l=rob(root->left);
                add(root->left,l);
            }
        }
        if(root->right!=NULL){
            if(!find(root->right->left,rl)){
                rl=rob(root->right->left);
                add(root->right->left,rl);
            }
            if(!find(root->right->right,rr)){
                rr=rob(root->right->right);
                add(root->right->right,rr);
            }
            if(!find(root->right,r)){
                r=rob(root->right);
                add(root->right,r);
            }
            
        }
        return max(root->val+ll+lr+rl+rr,l+r);
    }
    void add(TreeNode* root,int re){
        if(root!=NULL) dp[root]=re;
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