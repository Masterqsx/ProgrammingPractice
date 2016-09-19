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
    ListNode* deleteDuplicates(ListNode* head) {
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur!=NULL){
            if((cur->next!=NULL)&&(cur->next->val==cur->val)){//When after deleting, only one element in the list
                cur=dupDelete(cur);
                if(pre==NULL) head=cur; //When all the nodes is duplicated
            }
            else{
                if(pre==NULL) head=pre=cur;
                else{
                    pre->next=cur;
                    pre=cur;
                }
                cur=cur->next;
            }
        }
        if(pre) pre->next=NULL;  //When after deleting, no element is in the list.
        return head;
    }
    ListNode* dupDelete(ListNode* head){
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* temp=NULL;
        while((head->next!=NULL)&&(head->next->val==head->val)){
            temp=head->next;
            delete head;
            head=temp;
        }
        temp=head->next;
        delete head;
        return temp;
    }
};