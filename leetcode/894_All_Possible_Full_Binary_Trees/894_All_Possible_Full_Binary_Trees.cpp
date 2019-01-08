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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res = vector<TreeNode*>();
        if (N % 2 == 0) return res;
        if (N == 1) {
            res.push_back(new TreeNode(0));
            return res;
        } 
        for (int leftSz = 1; leftSz <= N - 2; leftSz++) {
            vector<TreeNode*> leftPos = allPossibleFBT(leftSz);
            vector<TreeNode*> rightPos = allPossibleFBT(N - 1 - leftSz);
            if (leftPos.size() > 0 && rightPos.size() > 0) {
                for (TreeNode* leftNode : leftPos) {
                    for (TreeNode* rightNode : rightPos) {
                        TreeNode* root = new TreeNode(0);
                        root->left = leftNode;
                        root->right = rightNode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
