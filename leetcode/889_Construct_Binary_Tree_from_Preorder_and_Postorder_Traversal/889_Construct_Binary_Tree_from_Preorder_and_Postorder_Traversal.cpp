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
    TreeNode* recursive(vector<int>& pre, vector<int>& post, int preLeft, int preRight, int postLeft, int postRight) {
        if (preRight - preLeft <= 0) return NULL;
        if (preRight - preLeft == 1) return new TreeNode(pre[preLeft]);
        int left = pre[preLeft + 1];
        int right = post[postRight - 2];
        TreeNode* root = new TreeNode(pre[preLeft]);
        if(left == right) {
            root->left = recursive(pre, post, preLeft + 1, preRight, postLeft, postRight - 1);
        }
        else {
            int leftIndex = postRight - 1;
            for (; leftIndex >= postLeft; leftIndex--) {
                if (post[leftIndex] == left) break;
            }
            int rightIndex = preLeft;
            for (; rightIndex < preRight; rightIndex++) {
                if (pre[rightIndex] == right) break;
            }
            root->left = recursive(pre, post, preLeft + 1, rightIndex, postLeft, leftIndex + 1);
            root->right = recursive(pre, post, rightIndex, preRight, leftIndex + 1, postRight - 1);
        }
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return recursive(pre, post, 0, pre.size(), 0, post.size());
    }
};
