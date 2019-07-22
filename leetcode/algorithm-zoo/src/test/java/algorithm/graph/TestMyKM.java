package algorithm.graph;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TestMyKM {

    private int[][] table1;

    private int[][] table2;

    @Before
    public void setUp() {
        table1 = new int[][]{
                {3, 5, 5, 4, 1, -1},
                {2, 2, 0, 2, 2, -1},
                {2, 4, 4, 1, 0, -1},
                {0, 1, 1, 0, 0, -1},
                {1, 2, 1, 3, 3, -1}
        };

        table2 = new int[][]{
                {-3, -5, -5, -4, -1},
                {-2, -2, -0, -2, -2},
                {-2, -4, -4, -1, -0},
                {-0, -1, -1, -0, -0},
                {-1, -2, -1, -3, -3}
        };
    }

    @Test
    public void testSolve() {
        int[] x1MatchActual = MyKM.solve(table1);
        int x1MatchExpectSum = 14;
        for (int i = 0; i < x1MatchActual.length; i++) x1MatchExpectSum -= table1[i][x1MatchActual[i]];
        Assert.assertEquals(x1MatchExpectSum, 0);

        int[] x2MatchActual = MyKM.solve(table2);
        int x2MatchExpectSum = -4;
        for (int i = 0; i < x2MatchActual.length; i++) x2MatchExpectSum -= table2[i][x2MatchActual[i]];
        Assert.assertEquals(x2MatchExpectSum, 0);
    }
}
