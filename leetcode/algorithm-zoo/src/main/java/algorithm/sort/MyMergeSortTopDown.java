package algorithm.sort;

public class MyMergeSortTopDown {
    public static void sort(int[] array) {
        sort(array, 0, array.length - 1);
    }

    private static void sort(int[] array, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        sort(array, l, mid);
        sort(array, mid + 1, r);

        int[] temp = new int[r - l + 1];
        int i = l, j = mid + 1, cur = 0;
        while (i <= mid && j <= r) {
            if (array[i] < array[j]) temp[cur] = array[i++];
            else temp[cur] = array[j++];
            cur++;
        }
        while (i <= mid) temp[cur++] = array[i++];
        while (j <= r) temp[cur++] = array[j++];

        for (int k = 0; k < temp.length; k++) {
            array[k + l] = temp[k];
        }
    }

}
