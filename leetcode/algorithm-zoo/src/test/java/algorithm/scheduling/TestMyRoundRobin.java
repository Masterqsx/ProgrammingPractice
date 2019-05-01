package algorithm.scheduling;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TestMyRoundRobin {
    private MyRoundRobin rb;

    @Before
    public void setUp() {
        rb = new MyRoundRobin(new int[]{5, 1, 1});
    }

    @Test
    public void testEqualPoll() {
        int[] expected = new int[]{0, 1, 2, 0, 1, 2};
        for (int i = 0; i < expected.length; i++) {
            Assert.assertEquals(expected[i], rb.equalPoll());
        }
    }

    @Test
    public void testWeightedPollLKS() {
        int[] expected = new int[]{0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 2};
        for (int i = 0; i < expected.length; i++) {
            Assert.assertEquals(expected[i], rb.weightedPollLKS());
        }
    }

    @Test
    public void testWeightedPollNginx() {
        int[] expected = new int[]{0, 0, 1, 0, 2, 0, 0, 0, 0, 1, 0, 2, 0, 0};
    for (int i = 0; i < expected.length; i++) {
            Assert.assertEquals(expected[i], rb.weightedPollNginx());
        }}
}
