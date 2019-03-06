package algorithm.segment_tree;

import algorithm.segment_tree.MyZKWSegmentTree;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class TestMyZKWSegmentTree {
    @Test
    public void testUpdateAndQuery() {
        int[] range = {5, 9, 7, 4, 6, 1, 4, 6};
        MyZKWSegmentTree st = new MyZKWSegmentTree(range);
        for (int i = 0; i < range.length; i++) {
            assertTrue(st.query(i, i) == range[i]);
        }
        st.updateSingle(0, 10);
        assertTrue(st.query(0, 3) == 30);
        assertTrue(st.query(2, 4) == 17);
    }
}
