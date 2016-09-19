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
    vector<TreeNode*> pointer;
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        inorder(root);
        int lo = 0, hi = pointer.size()-1;
        bool f_l = false, f_h = false;
        while (lo <= hi){
            if (!f_l && pointer[lo]->val > pointer[lo+1]->val) f_l = true;
            else if (!f_l) lo++;
            if (!f_h && pointer[hi]->val < pointer[hi-1]->val) f_h = true;
            else if (!f_h) hi--;
            if (f_l && f_h) break;
        }
        int t = pointer[lo]->val;
        pointer[lo]->val = pointer[hi]->val;
        pointer[hi]->val = t;
    }
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
        pointer.push_back(root);
        inorder(root->right);
    }
};
