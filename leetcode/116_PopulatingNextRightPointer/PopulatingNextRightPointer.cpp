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
        TreeLinkNode* start=root;
        TreeLinkNode* cur=root;
        if(root==NULL) return;
        while(start->left!=NULL){
            while(cur!=NULL){
                cur->left->next=cur->right;
                cur->right->next=cur->next==NULL?NULL:cur->next->left;
                cur=cur->next;
            }
            cur=start=start->left;
        }
    }
};