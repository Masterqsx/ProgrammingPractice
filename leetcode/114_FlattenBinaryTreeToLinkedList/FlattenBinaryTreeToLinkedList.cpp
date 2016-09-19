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
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        TreeNode* pre=NULL;
        recursive(cur,pre);
        cur=root;
        while(cur!=NULL){
            cur->right=cur->left;
            TreeNode* temp=cur->left;
            cur->left=NULL;
            cur=temp;
        }
    }
    void recursive(TreeNode* root,TreeNode*& end){
        if(root==NULL) return;
        if(end!=NULL) end->left=root;
        end=root;
        recursive(root->left,end);
        recursive(root->right,end);
    }
};