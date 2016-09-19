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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        recursive(root,0,sum);
        return sum;
    }
    void recursive(TreeNode* root,int cur,int& sum){
        if(root==NULL) return;
        cur=cur*10+root->val;
        if((root->left==NULL)&&(root->right==NULL)){
            sum+=cur;
            return;
        }
        recursive(root->left,cur,sum);
        recursive(root->right,cur,sum);
    }
};