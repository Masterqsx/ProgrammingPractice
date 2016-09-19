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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode* cur=root;
        int level=0,num=0;
        while(cur->left!=NULL){
            level++;
            cur=cur->left;
        }
        recursive(level,root,num);
        return ((1<<(level+1))-1-num);
    }
    void recursive(int level,TreeNode* root,int& num){
        if(level==0) num=root==NULL?num+1:num;
        else{
            int count=0;
            TreeNode* pre=root->left;
            while(pre!=NULL){
                count++;
                pre=pre->right;
            }
            if(count<level){
                num=num*2+1;
                recursive(level-1,root->left,num);
            }
            else{
                num=num*2;
                recursive(level-1,root->right,num);
            }
        }
    }
};