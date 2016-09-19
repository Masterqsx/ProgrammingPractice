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
        if(size==0) return NULL;
        if(size==1) return begin;
        int size_left=(size+1)/2;
        int count=1;
        ListNode* mid=begin;
        while(count<size_left){
            count++;
            mid=mid->next;
        }
        ListNode* temp=mid->next;
        mid->next=NULL;
        return merge(mergeSort(begin,size_left),mergeSort(temp,size-size_left));
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