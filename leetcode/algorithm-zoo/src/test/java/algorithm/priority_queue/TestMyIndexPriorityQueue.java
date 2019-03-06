package algorithm.priority_queue;

import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

import static org.junit.Assert.assertTrue;

public class TestMyIndexPriorityQueue {
    public class Dummy {
        public int n;
        public Dummy(int n) {
            this.n = n;
        }
    }

    @Test
    public void testHashMapReference() {
        Map<Dummy, Integer> m = new HashMap<>();
        Dummy i1 = new Dummy(1);
        Dummy i2 = new Dummy(2);
        m.put(i1, new Integer(3));
        m.put(i2, new Integer(4));
        i1.n = 3;
        assertTrue(m.get(i1) == 3);
    }

    @Test
    public void testSorting() {
        MyIndexPriorityQueue<Dummy> pq = new MyIndexPriorityQueue<>((l, r) -> l.n - r.n);
        int[] testCase1 = {19, 2, 44, -1, 100, 20, 2, 19, -2147483, 21474837};
        Dummy[] testCase2 = new Dummy[testCase1.length];
        int[] verifyCase1 = {-1, 2, 3, 19, 19, 20, 44, 100};

        for (int i = 0; i < testCase1.length; i++) {
            testCase2[i] = new Dummy(testCase1[i]);
            pq.insert(testCase2[i]);
        }

        // delete arbitrary
        pq.delete(testCase2[testCase2.length - 1]);
        pq.delete(testCase2[testCase2.length - 2]);

        // update arbitrary
        testCase2[1].n = 3;
        pq.update(testCase2[1]);

        for (int i = 0; i < verifyCase1.length; i++) {
            assertTrue(pq.top().n == verifyCase1[i]);
            pq.delTop();
        }
    }
}
