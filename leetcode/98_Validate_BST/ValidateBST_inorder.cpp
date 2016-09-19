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
    bool InorderTraversal(TreeNode* node,TreeNode* &pre){
        if(node==NULL)
            return true;
        if(!InorderTraversal(node->left,pre))
            return false;
        if(pre!=NULL&&pre->val>=node->val)
            return false;
        pre=node;
        return InorderTraversal(node->right,pre);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=NULL;
        return InorderTraversal(root,pre);
        
    }
};