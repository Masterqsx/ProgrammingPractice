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
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* end=NULL;
        ListNode* mid=NULL;
        ListNode* fakehead=new ListNode(0);
        int count=1;
        while(count<=n){
            if(count>=m){
                end=cur->next;
                cur->next=fakehead->next;
                if(count==m) mid=cur;
                fakehead->next=cur;
                cur=end;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
            count++;
        }
        if(pre==NULL) head=fakehead->next;
        else pre->next=fakehead->next;
        mid->next=end;
        delete fakehead;
        return head;
    }
};