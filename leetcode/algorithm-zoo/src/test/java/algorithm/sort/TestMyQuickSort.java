package algorithm.sort;

import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.assertTrue;

public class TestMyQuickSort {
    private static final int N = 10000000;
    @Test
    public void testSort() {
        int[] arrExpected = new int[N];
        int[] arrActual1 = new int[N];
        int[] arrActual2 = new int[N];
        int[] arrActual3 = new int[N];
        for (int i = 0; i < N; i++) {
            arrExpected[i] = (int)(Math.random() * 2 * N - N);
            arrActual1[i] = arrExpected[i];
            arrActual2[i] = arrExpected[i];
            arrActual3[i] = arrExpected[i];
        }
        long start0 = System.nanoTime();
        Arrays.sort(arrExpected);
        long end0 = System.nanoTime();

        long start1 = System.nanoTime();
        MyQuickSortBasic.sort(arrActual1, 0, N - 1);
        long end1 = System.nanoTime();

        long start2 = System.nanoTime();
        MyQuickSort3Way.sort(arrActual2, 0, N - 1);
        long end2 = System.nanoTime();

        long start3 = System.nanoTime();
        MyQuickSortDualPivot.sort(arrActual3, 0, N - 1);
        long end3 = System.nanoTime();

        for (int i = 0; i < N; i++) {
            assertTrue(arrExpected[i] == arrActual1[i]);
            assertTrue(arrExpected[i] == arrActual2[i]);
            assertTrue(arrExpected[i] == arrActual3[i]);
        }

        System.out.println("Java Library Performance : " + (end0 - start0));
        System.out.println("MyQuickSortBasic Performance : " + (end1 - start1));
        System.out.println("MyQuickSort3Way Performance : " + (end2 - start2));
        System.out.println("MyQuickSortDualPivot Performance : " + (end3 - start3));
    }
}
