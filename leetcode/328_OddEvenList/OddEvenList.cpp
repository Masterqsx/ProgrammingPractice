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
    ListNode* oddEvenList(ListNode* head) {
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* evenHead=new ListNode(0);
        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* even_cur=evenHead;
        int count=2;
        while(cur!=NULL){
            if(count%2==0){
                pre->next=cur->next;
                cur->next=NULL;
                even_cur->next=cur;
                even_cur=even_cur->next;
                cur=pre->next;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
            count++;
        }
        pre->next=evenHead->next;
        delete evenHead;
        return head;
    }
};