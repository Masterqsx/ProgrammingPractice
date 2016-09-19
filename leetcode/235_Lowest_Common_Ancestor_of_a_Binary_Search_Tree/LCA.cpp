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
    class state {
    public:
        bool st;
        int n;
        state(bool i_st, int i_n): st(i_st), n(i_n){}
    };
    TreeNode* lca = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return lca;
    }
    state helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL) return state(false, 0);
        state re_l = helper(root->left, p, q);
        state re_r = helper(root->right, p, q);
        if (re_l.st || re_r.st) return state(true, 2);
        if (root->val == p->val || root->val == q->val){
            if (re_l.n == 1 || re_r.n == 1){
                lca = root;
                return state(true, 2);
            }
            else return state(false, 1);
        }
        else {
            if (re_l.n == 1 && re_r.n == 1){
                lca = root;
                return state(true, 2);
            }
            else return state(false, re_l.n+re_r.n);
        }
    }
};
