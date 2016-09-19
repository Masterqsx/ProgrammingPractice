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
        ListNode* fakehead=new ListNode(0);
        fakehead->next=head;
        ListNode* pre=fakehead;
        ListNode* before=fakehead;
        ListNode* cur=head;
        while(cur!=NULL){
            if(cur->val<x){
                if(before->next!=cur){
                    before=listInsert(before,listDelete(pre,cur));
                    cur=pre->next;
                    continue;
                }
                else before=before->next;
                
            }
            pre=cur;
            cur=cur->next;
            
        }
        head=fakehead->next;
        delete fakehead;
        return head;
    }
    ListNode* listInsert(ListNode* cur,ListNode* inserted){
        if(cur==NULL) return NULL;
        inserted->next=cur->next;
        cur->next=inserted;
        return inserted;
    }
    ListNode* listDelete(ListNode* pre,ListNode* cur){
        if(cur==NULL) return NULL;
        if(pre!=NULL) pre->next=cur->next;
        cur->next=NULL;
        return cur;
    }
};