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
        stack<TreeNode*> stack;
        stack.push(root);
        unordered_map<TreeNode*,bool> checklist;
        checklist[root]=true;
        if(root==NULL) return re;
        while(!stack.empty()){
            TreeNode* temp=stack.top();
            if((temp->left!=NULL)&&(checklist.find(temp->left)==checklist.end())){
                stack.push(temp->left);
                checklist[temp->left]=true;
            }
            else{
                re.push_back(temp->val);
                stack.pop();
                if(temp->right!=NULL)
                    stack.push(temp->right);
            }
        }
        return re;
    }
};