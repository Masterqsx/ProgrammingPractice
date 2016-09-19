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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return n_l(l_n(l1)+l_n(l2));
    }
    long l_n(ListNode* l){
        long result=0,level=0;
        while(l!=NULL){
            result=result+l->val*pow(10,level);
            l=l->next;
            level++;
        }
        return result;
    }
    ListNode* n_l(long n){
        ListNode* result=NULL;
        if(n==0){
            result=new ListNode(0);
        }
        else{
            ListNode* t=NULL;
            while(n!=0){
                ListNode* cur=new ListNode(n-n/10*10);
                if(result==NULL) result=cur;
                else{
                    t->next=cur;
                }
                n=n/10;
                t=cur;
            }
        }
        return result;
    }
};