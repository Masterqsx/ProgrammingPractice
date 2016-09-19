/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        root->next = NULL;
        TreeLinkNode* start = root;
        TreeLinkNode* pre = NULL;
        while (start != NULL){
            root = start;
            start = NULL;
            pre = NULL;
            while (root != NULL){
                if (root->left) {
                    if (!start) start = root->left;
                    root->left->next = root->right;
                    pre = root->left;
                }
                else if (pre) pre->next = root->right;
                if (root->right) {
                    pre = root->right;
                    if (!start) start = root->right;
                    if (!root->next) root->right->next = NULL;
                    else root->right->next = root->next->left;
                }
                else if (pre) pre->next = root->next == NULL?NULL:root->next->left;
                root = root->next;
            }
        }
    }
};
