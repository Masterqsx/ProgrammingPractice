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
    ListNode *detectCycle(ListNode *head) {
        if((head==NULL)||(head->next==NULL)) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while((fast!=NULL)&&(fast->next!=NULL)){//if no cycle will quit
            slow=slow->next;
            fast=(flag==false)?fast->next->next:fast->next;
            if((slow==fast)&&(flag==false)){//find the encounter position
                flag=true;
                slow=head;
            }
            if((slow==fast)&&(flag==true)) return slow;
        }
        return NULL;
    }
};