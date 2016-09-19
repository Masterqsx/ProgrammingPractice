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
    TreeNode* lca = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p , q);
        return lca;
    }
    void helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL) return;
        else if (root->val == p->val || root->val == q->val){
            lca = root;
            return;
        }
        else if (root->val > p->val && root->val < q->val || root->val > q->val && root->val < p->val){
            lca = root;
            return;
        }
        else if (root->val > p->val && root->val > q->val) helper(root->left, p, q);
        else helper(root->right, p , q);
    }
};
