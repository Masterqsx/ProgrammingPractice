package algorithm.segment_tree;

import algorithm.segment_tree.MySegmentTree;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class TestSegmentTree {
    @Test
    public void testUpdateSingleAndQuery() {
        MySegmentTree st = new MySegmentTree(6);
        int[] testCase = {5, 9, 7, 4, 6, 1};
        for (int i = 0; i < testCase.length; i++) {
            st.updateSingle(i, testCase[i]);
        }
        for (int i = 0; i < testCase.length; i++) {
            assertTrue(st.query(i, i) == testCase[i]);
        }
        assertTrue(st.query(0, 3) == 9);
        assertTrue(st.query(2, 4) == 7);
    }

    @Test
    public void testUpdateAndQuery() {
        MySegmentTree st = new MySegmentTree(6);
        int[] testCase = {5, 9, 7, 4, 6, 1};
        for (int i = 0; i < testCase.length; i++) {
            st.updateSingle(i, testCase[i]);
        }
        for (int i = 0; i < testCase.length; i++) {
            assertTrue(st.query(i, i) == testCase[i]);
        }
        assertTrue(st.query(0, 3) == 9);
        assertTrue(st.query(2, 4) == 7);

        st.update(0, 4, -3);
        assertTrue(st.query(0, 2) == 6);
        assertTrue(st.query(0, 1) == 6);
        assertTrue(st.query(3, 4) == 3);
    }
}
