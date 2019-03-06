package algorithm.segment_tree;

import algorithm.segment_tree.MyZKWQuadSegmentTree;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestMyZKWQuadSegmentTree {
    @Test
    public void testUpdateSingleAndQuery() {
        int[][] testCase = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
        };
        MyZKWQuadSegmentTree st = new MyZKWQuadSegmentTree(testCase);

        for (int i = 0; i < testCase.length; i++) {
            for (int j = 0; j < testCase[i].length; j++) {
                assertEquals(testCase[i][j], st.query(i, i, j, j));
            }
        }
        assertEquals(8, st.query(2, 4, 1, 3));
        st.updateSingle(3, 2, 2);
        assertEquals(10, st.query(2, 4, 1, 3));
    }

    @Test
    public void testCornerCase() {
        int[][] testCase = {
            {0, -5, 9, 1, -8, 5, 8, 1, 1, 5}
        };
        MyZKWQuadSegmentTree st = new MyZKWQuadSegmentTree(testCase);
        assertEquals(20, st.query(0, 0, 5, 9));
        assertEquals(6, st.query(0, 0, 3, 6));
        st.updateSingle(0, 3, -1);
        assertEquals(4, st.query(0, 0, 3, 6));
    }
}
