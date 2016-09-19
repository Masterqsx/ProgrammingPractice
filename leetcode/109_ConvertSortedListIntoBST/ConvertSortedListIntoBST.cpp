/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return (new TreeNode(head->val));
        ListNode* cur=head;
        int count=0;
        while(cur!=NULL){
            count++;
            cur=cur->next;
        }
        return buildBST(head,count);
    }
    TreeNode* buildBST(ListNode* start,int size){
        if(size==0) return NULL;
        if(size==1) return (new TreeNode(start->val));
        int mid=(size+1)/2,count=1;
        ListNode* cur=start;
        ListNode* pre=NULL;
        while(count<mid){
            count++;
            pre=cur;
            cur=cur->next;
        }
        TreeNode* root=new TreeNode(cur->val);
        root->left=buildBST(start,mid-1);
        root->right=buildBST(cur->next,size-mid);
        return root;
    }
};