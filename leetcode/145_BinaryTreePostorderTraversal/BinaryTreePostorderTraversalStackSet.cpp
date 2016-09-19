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
        unordered_set<TreeNode*> visited;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode* cur=nodeStack.top();
            if(((cur->left==NULL)||(visited.find(cur->left)!=visited.end()))&&((cur->right==NULL)||(visited.find(cur->right)!=visited.end()))){
                re.push_back(cur->val);
                visited.insert(cur);
                nodeStack.pop();
            }
            else{
                if((cur->left!=NULL)&&(visited.find(cur->left)==visited.end())){
                    nodeStack.push(cur->left);
                }
                else if((cur->right!=NULL)&&(visited.find(cur->right)==visited.end())){
                    nodeStack.push(cur->right);
                }
            }
            
            
        }
        return re;
    }
};