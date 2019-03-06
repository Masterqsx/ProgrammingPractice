package algorithm.priority_queue;

import algorithm.priority_queue.MyPriorityQueue;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class TestMyPriorityQueue {

    @Test
    public void testComparator() {
        MyPriorityQueue<Integer> pq = new MyPriorityQueue<>((l, r) -> l - r);
        pq.insert(10);
        pq.insert(100);
        pq.insert(1);
        assertTrue(pq.top() == 1);
    }

    @Test
    public void testSorting() {
        MyPriorityQueue<Integer> pq = new MyPriorityQueue<>((l, r) -> l - r);
        int[] testCase1 = {19, 2, 44, -1, 100, 20, 2, 19, -2147483, 21474837};
        int[] verifyCase1 = {-2147483, -1, 2, 2, 19, 19, 20, 44, 100, 21474837};
        for (int n : testCase1) {
            pq.insert(new Integer(n));
        }
        for (int i = 0; i < verifyCase1.length; i++) {
            assertTrue(pq.top() == verifyCase1[i]);
            pq.delTop();
        }
    }
}
