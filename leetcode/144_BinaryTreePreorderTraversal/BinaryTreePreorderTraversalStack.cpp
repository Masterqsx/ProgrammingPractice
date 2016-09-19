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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        if(root==NULL) return re;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode* cur=nodeStack.top();
            nodeStack.pop();
            re.push_back(cur->val);
            if(cur->right!=NULL){
                nodeStack.push(cur->right);
            }
            if(cur->left!=NULL){
                nodeStack.push(cur->left);
            }
        }
        return re;
    }
};