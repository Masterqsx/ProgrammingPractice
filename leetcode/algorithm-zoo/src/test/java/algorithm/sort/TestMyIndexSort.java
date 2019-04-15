package algorithm.sort;

import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class TestMyIndexSort {
    private static final int N = 1000000;

    @Test
    public void testSort() {
        int[] expected = new int[N];
        for (int i = 0; i < N; i++) expected[i] = (int) (Math.random() * N);
        int[] actual1 = Arrays.copyOf(expected, N);

        long start0 = System.nanoTime();
        Arrays.sort(expected);
        long end0 = System.nanoTime();

        long start1 = System.nanoTime();
        MyIndexSort.sort(actual1);
        long end1 = System.nanoTime();

        Assert.assertTrue(Arrays.equals(expected, actual1));

        System.out.println("Java Library Performance : " + (end0 - start0));
        System.out.println("MyIndexSort Performance : " + (end1 - start1));
    }
}
