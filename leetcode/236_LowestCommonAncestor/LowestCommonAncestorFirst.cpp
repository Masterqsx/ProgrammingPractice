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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        findPath(root,p,p_path);
        findPath(root,q,q_path);
        int i=0;
        for(;i<min(p_path.size(),q_path.size());i++){
            if(p_path[i]!=q_path[i]) break;
        }
        return p_path[i-1];
    }
    bool findPath(TreeNode* root,TreeNode* target,vector<TreeNode*>& path){
        if(root==NULL) return false;
        if(root==target){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if(!findPath(root->left,target,path)){
            if(!findPath(root->right,target,path)){
                path.pop_back();
                return false;
            }
            return true;
        }
        return true;
        
    }
};