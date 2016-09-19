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
    bool isleftValid(TreeNode* nodes,int target){
        if(nodes==NULL)
            return true;
        else if( nodes->val>=target )
            return false;
        else
            return isleftValid(nodes->left,target)&&isleftValid(nodes->right,target);
    }
    
    bool isrightValid(TreeNode* nodes,int target){
        if(nodes==NULL)
            return true;
        else if( nodes->val<=target )
            return false;
        else
            return isrightValid(nodes->left,target)&&isrightValid(nodes->right,target);
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isleftValid(root->left,root->val)&&isrightValid(root->right,root->val)&&isValidBST(root->left)&&isValidBST(root->right);
        
    }
};