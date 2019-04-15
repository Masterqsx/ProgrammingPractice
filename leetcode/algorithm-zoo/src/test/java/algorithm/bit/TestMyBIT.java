package algorithm.bit;

import org.junit.Assert;
import org.junit.Test;

public class TestMyBIT {
    private static final int N = 10000;
    private static final int updateVal = (int)Math.round(Math.random() * N);
    private static final int updateIdx = (int)Math.round(Math.random() * N);

    @Test
    public void test() {
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = (int)Math.random() * N;
        }

        MyBIT bit = new MyBIT(arr);

        int[] cummu = new int[N];

        arr[updateIdx] += updateVal;
        bit.update(updateIdx, updateVal);

        cummu[0] = arr[0];
        for (int i = 1; i < N; i++) {
            cummu[i] = cummu[i - 1] + arr[i];
        }

        for (int i = 0; i < N; i++) {
            Assert.assertEquals(cummu[i], bit.query(i));
        }
    }
}
