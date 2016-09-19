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
    void reorderList(ListNode* head) {
        if((head==NULL)||(head->next==NULL)||(head->next->next==NULL)) return;
        ListNode* fakehead=new ListNode(0);
        ListNode* cur=head->next;
        ListNode* temp=NULL;
        int count=1;
        while(cur!=NULL){
            cur=cur->next;
            count++;
        }
        int mid=count/2;
        count=1;
        cur=head->next;
        while(cur!=NULL){
            if(count<=mid){
                if(count==mid) temp=cur;
                cur=cur->next;
                if(count==mid) temp->next=NULL;
                count++;
            }
            else{
                temp=cur->next;
                cur->next=fakehead->next;
                fakehead->next=cur;
                cur=temp;
            }
        }
        
        ListNode* cur0=head->next;
        ListNode* cur1=fakehead->next;
        cur=head;
        while((cur0!=NULL)||(cur1!=NULL)){
            if(cur1!=NULL){
                cur->next=cur1;
                cur1=cur1->next;
                cur=cur->next;
            }
            if(cur0!=NULL){
                cur->next=cur0;
                cur0=cur0->next;
                cur=cur->next;
            }
        }
        delete fakehead;
    }
};