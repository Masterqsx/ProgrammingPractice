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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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