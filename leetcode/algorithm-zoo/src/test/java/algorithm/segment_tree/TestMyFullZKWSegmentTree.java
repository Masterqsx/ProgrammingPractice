package algorithm.segment_tree;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class TestMyFullZKWSegmentTree {
    @Test
    public void testUpdateSumSingleAndQuery() {
        int[] range = {5, 9, 7, 4, 6, 1, 4, 6};
        MyFullZKWSegmentTree st = new MyFullZKWSegmentTree(range);
        for (int i = 0; i < range.length; i++) {
            assertTrue(st.querySum(i, i) == range[i]);
        }
        st.updateSingleSum(0, 10);
        assertTrue(st.querySum(0, 3) == 30);
        assertTrue(st.querySum(2, 4) == 17);
    }

    @Test
    public void testUpdateSumAndQuery() {
        int[] range = {5, 9, 7, 4, 6, 1, 4, 6};
        MyFullZKWSegmentTree st = new MyFullZKWSegmentTree(range);
        for (int i = 0; i < range.length; i++) {
            assertTrue(st.querySum(i, i) == range[i]);
        }
        st.updateSingleSum(0, 10);
        st.updateSum(0, 3, 15);
        assertTrue(st.querySum(0, 3) == 15 * 4 + 30);
        assertEquals(24, st.querySum(1, 1));
    }

    @Test
    public void testUpdateMaxAndQuery() {
        int[] range = {5, 9, 7, 4, 6, 1, 4, 6};
        MyFullZKWSegmentTree st = new MyFullZKWSegmentTree(range);
        for (int i = 0; i < range.length; i++) {
            assertEquals(range[i], st.queryMax(i, i));
        }
        st.updateSingleMax(0, 10);
        st.updateMax(0, 3, 15);
        assertEquals(st.querySum(0, 3), 25);
    }
}
