package algorithm.binary_search;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;

public class TestMyBinarySearch {

    private int[] arr;
    private static final int N = 1000;

    @Before
    public void setUp() {
        arr = new int[2 * N];
        for (int i = -N; i < N; i++) arr[i + N] = i;

    }

    @Test
    public void testBinarySearchEqualTarget() {
        for (int i = 0; i < N; i++) {
            int target = (int) (Math.random() * 4 * N) - 2 * N;
            int expect = Arrays.binarySearch(arr, target);
            int actual = MyBinarySearch.binarySearchEqualTarget(arr, target);
            Assert.assertEquals(expect >= 0 ? expect : -1, actual);
        }
    }
}
