package algorithm.sort;

import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

public class TestMyMergeSort {
    private static final int N = 10000;

    @Test
    public void testSort() {
        int[] expected = TestSortUtility.generateArray(N);
        int[] actual1 = Arrays.copyOf(expected, N);
        int[] actual2 = Arrays.copyOf(expected, N);
        int[] actual3 = Arrays.copyOf(expected, N);

        long start0 = System.nanoTime();
        Arrays.sort(expected);
        long end0 = System.nanoTime();

        long start1 = System.nanoTime();
        MyMergeSortInPlace.sort(actual1);
        long end1 = System.nanoTime();

        long start2 = System.nanoTime();
        MyMergeSortTopDown.sort(actual2);
        long end2 = System.nanoTime();

        long start3 = System.nanoTime();
        MyMergeSortBottomUp.sort(actual3);
        long end3 = System.nanoTime();

        Assert.assertTrue(Arrays.equals(expected, actual1));
        Assert.assertTrue(Arrays.equals(expected, actual2));
        Assert.assertTrue(Arrays.equals(expected, actual3));

        System.out.println("Java Library Performance : " + (end0 - start0));
        System.out.println("MyMergeSortInPlace Performance : " + (end1 - start1));
        System.out.println("MyMergeSortTopDown Performance : " + (end2 - start2));
        System.out.println("MyMergeSortBottomUp Performance : " + (end3 - start3));
    }
}
