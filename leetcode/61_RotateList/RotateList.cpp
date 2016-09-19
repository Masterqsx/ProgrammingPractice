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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* cur=NULL;
        ListNode* pre=NULL;
        ListNode* end=head;
        unsigned count=0;
        while(end!=NULL){
            count++;
            cur=end;
            end=end->next;
        }
        if(k%count!=0){
            end=cur;
            k=count-k%count;
            cur=head;
            while(k>0){
                pre=cur;
                cur=cur->next;
                k--;
            }
            end->next=head;
            pre->next=NULL;
            head=cur;
        }
        return head;
    }
};