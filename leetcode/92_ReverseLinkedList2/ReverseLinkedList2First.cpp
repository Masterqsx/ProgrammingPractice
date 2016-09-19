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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if((head==NULL)||(head->next==NULL)||(m==n)) return head;
        ListNode* cur=head;
        ListNode* pre=NULL;
        int count=1;
        while(count<m){
            count++;
            pre=cur;
            cur=cur->next;
        }
        ListNode* fakehead=new ListNode(0);
        if(pre!=NULL){
            pre->next=reverse(fakehead,m,n,m,cur);
        }
        else{
            head=reverse(fakehead,m,n,m,cur);
        }
        delete fakehead;
        return head;
    }
    ListNode* reverse(ListNode* start,int level,int n,int m,ListNode* cur){
        if(level==n){
            start->next=(cur==NULL)?NULL:cur->next;
            cur->next=NULL;
            return cur;
        }
        else{
            ListNode* temp=reverse(start,level+1,n,m,cur->next);
            cur->next->next=cur;
            cur->next=(level==m)?start->next:NULL;
            return temp;
        }
    }
};