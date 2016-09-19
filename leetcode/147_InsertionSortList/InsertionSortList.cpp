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
    ListNode* insertionSortList(ListNode* head) {
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* fakehead=new ListNode(INT_MIN);
        fakehead->next=head;
        ListNode* sorted=head;
        ListNode* cur=head->next;
        ListNode* temp=NULL;
        while(cur!=NULL){
            if(cur->val>=sorted->val){
                sorted=cur;
                cur=cur->next;
            }
            else{
                temp=cur->next;
                ListNode* inserted=listDelete(sorted,cur);
                ListNode* insert_before=fakehead;
                ListNode* insert_after=fakehead->next;//head will be changed. The true head is the fakehead->next.
                while((inserted->val>insert_after->val)&&(insert_after!=NULL)){
                    insert_before=insert_after;
                    insert_after=insert_after->next;
                }
                listInsertion(insert_before,inserted);
                cur=temp;
            }
        }
        temp=fakehead->next;
        delete fakehead;
        return temp;
    }
    ListNode* listInsertion(ListNode* cur,ListNode* inserted){
        if((cur==NULL)||(inserted==NULL)) return NULL;
        ListNode* temp=cur->next;
        inserted->next=cur->next;
        cur->next=inserted;
        return temp;
    }
    ListNode* listDelete(ListNode* pre,ListNode* cur){
        if(cur==NULL) return NULL;
        if(pre) pre->next=cur->next;
        cur->next=NULL;
        return cur;
    }
};