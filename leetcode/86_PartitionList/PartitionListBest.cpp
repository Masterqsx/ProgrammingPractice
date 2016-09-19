/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* fakehead1=new ListNode(0);
        ListNode* fakehead2=new ListNode(0);
        ListNode* cur=head;
        ListNode* cur_less=fakehead1;
        ListNode* cur_more=fakehead2;
        while(cur!=NULL){
            if(cur->val<x){
                cur_less->next=cur;
                cur=cur->next;
                cur_less=cur_less->next;
                cur_less->next=NULL;
            }
            else{
                cur_more->next=cur;
                cur=cur->next;
                cur_more=cur_more->next;
                cur_more->next=NULL;
            }
        }
        cur_less->next=fakehead2->next;
        head=fakehead1->next;
        delete fakehead1;
        delete fakehead2;
        return head;
        
    }
};