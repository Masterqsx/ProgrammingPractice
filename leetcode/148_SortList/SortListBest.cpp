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
    ListNode* sortList(ListNode* head) {
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* cur=head;
        int count=0;
        while(cur!=NULL){
            cur=cur->next;
            count++;
        }
        return mergeSort(head,count);
        
    }
    ListNode* mergeSort(ListNode* begin,int size){
        ListNode* fakehead=new ListNode(0);
        fakehead->next=begin;
        for(int n=1;n<size;n=n*2){
            ListNode* new_begin=fakehead->next;
            ListNode* end=fakehead;
            for(int i=0;i<size;i+=n*2){
                ListNode* l1=new_begin;
                new_begin=split(l1,2*n);
                ListNode* l2=split(l1,n);
                end->next=merge(l1,l2);
                end=findEnd(end->next);
            }
        }
        ListNode* temp=fakehead->next;
        delete fakehead;
        return temp;
    }
    ListNode* split(ListNode* head,int size){//return mid+1
        int count=1;
        ListNode* cur=head;
        while((count<size)&&(cur!=NULL)){
            count++;
            cur=cur->next;
        }
        if(cur!=NULL){
            ListNode* temp=cur->next;
            cur->next=NULL;
            return temp;
        }
        else{
            return NULL;
        }
    }
    ListNode* findEnd(ListNode* head){
        if((head==NULL)||(head->next==NULL)) return head;
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur!=NULL){
            pre=cur;
            cur=cur->next;
        }
        return pre;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* fakehead=new ListNode(0);
        ListNode* cur=fakehead;
        while((l1!=NULL)||(l2!=NULL)){
            if((l1!=NULL?l1->val:INT_MAX)>(l2!=NULL?l2->val:INT_MAX)){
                cur->next=l2;
                l2=l2->next;
            }
            else{
                cur->next=l1;
                l1=l1->next;
            }
            cur=cur->next;
        }
        cur=fakehead->next;
        delete fakehead;
        return cur;
    }
};