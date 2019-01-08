/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public ListNode root;
    
    public Random random;
    
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        root = head;
        random = new Random();
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        ListNode cur = root;
        int i = 1, res = 0;
        while (cur != null) {
            if (random.nextInt(i) < 1) res = cur.val;
            cur = cur.next;
            i++;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
