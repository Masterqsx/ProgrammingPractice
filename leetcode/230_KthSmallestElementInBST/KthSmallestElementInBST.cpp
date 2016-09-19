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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        int answer=0;
        recursive(root,k,answer);
        return answer;
    }
    void recursive(TreeNode* root,int& k,int& answer){
        if(root==NULL) return;
        recursive(root->left,k,answer);
        k--;
        if(k==0){
            answer=root->val;
            return;
        }
        recursive(root->right,k,answer);
    }
};