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
    long MinInf = LONG_MIN;
    long MaxInf = LONG_MAX;
    bool isValid(TreeNode* node, long min,long max){
        if( node==NULL )
            return true;
        else if( (node->val<=min)||(node->val>=max) )
            return false;
        else
            return isValid(node->left,min,(long)node->val)&&isValid(node->right,(long)node->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,MinInf,MaxInf);
    }
};