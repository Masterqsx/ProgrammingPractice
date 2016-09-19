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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        if(root==NULL) return re;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode* cur=nodeStack.top();
            if((cur->left==NULL)&&(cur->right==NULL)){
                re.push_back(cur->val);
                nodeStack.pop();
            }
            else{
                if(cur->left!=NULL){
                    nodeStack.push(cur->left);
                    cur->left=NULL;
                }
                else{
                    nodeStack.push(cur->right);
                    cur->right=NULL;
                }
            }
            
        }
        return re;
    }
};