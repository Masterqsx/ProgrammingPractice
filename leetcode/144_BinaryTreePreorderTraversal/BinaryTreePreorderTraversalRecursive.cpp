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
        traversal(root,re);
        return re;
    }
    void traversal(TreeNode* root, vector<int>& re){
        if(root==NULL) return;
        re.push_back(root->val);//preorder is the root is before the children
        traversal(root->left,re);
        traversal(root->right,re);
    }
};