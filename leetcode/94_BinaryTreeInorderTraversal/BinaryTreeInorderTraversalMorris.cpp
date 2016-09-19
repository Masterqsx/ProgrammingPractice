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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        if(root==NULL) return re;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                re.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* pre=cur->left;
                while((pre->right!=NULL)&&(pre->right!=cur)){//Find the predecessor
                    pre=pre->right;
                }
                if(pre->right==NULL){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    pre->right=NULL;
                    re.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return re;
    }
};