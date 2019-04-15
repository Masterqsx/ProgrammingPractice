package algorithm.sort;

public class MyIndexSort {
    public static void sort(int[] arr) {
        long mask = 10, pre = 1;
        while (mask < Integer.MAX_VALUE) {
            int[] count = new int[11];
            for (int num : arr) {
                long idx = (long)num % mask;
                idx /= pre;
                count[(int) idx + 1]++;
            }
            if (count[1] == arr.length) break;
            for (int i = 1; i < count.length; i++) count[i] += count[i - 1];
            int[] temp = new int[arr.length];
            for (int num : arr) {
                long idx = num % mask;
                idx /= pre;
                temp[count[(int)idx]++] = num;
            }
            for (int i = 0; i < arr.length; i++) arr[i] = temp[i];
            pre = mask;
            mask *= 10;
        }
    }
}
