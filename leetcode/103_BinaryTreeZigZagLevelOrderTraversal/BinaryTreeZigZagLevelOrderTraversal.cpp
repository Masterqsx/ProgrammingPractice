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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > re;
        recursive(re,0,true,root);
        return re;
    }
    void recursive(vector<vector<int> >& re,int level,bool order,TreeNode* root){//true left to right, false right to left
        if(root==NULL) return;
        if(re.size()<=level){
            re.push_back(vector<int>());
        }
        if(order){
            re[level].push_back(root->val);
        }
        else{
            re[level].insert(re[level].begin(),root->val);
        }
        recursive(re,level+1,!order,root->left);
        recursive(re,level+1,!order,root->right);
    }
};