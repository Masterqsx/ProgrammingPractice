package algorithm.sort;

public class MyMergeSortInPlace {
    public static void sort(int[] array) {
        sort(array, 0, array.length - 1);
    }

    public static void sort(int[] array, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        sort(array, l, mid);
        sort(array, mid + 1, r);
        merge(array, l, mid, mid + 1, r);
    }

    public static void merge(int[] array, int iS, int iE, int jS, int jE) {
        int i = iS, j = jS;
        while (i <= iE && j <= jE) {
            if (array[i] < array[j]) i++;
            else {
                int temp = array[j], k = j;
                while (k > i) {
                    swap(array, k, k - 1);
                    k--;
                }
                array[i] = temp;
                iE++; i++; j++;
            }
        }
    }

    public static void swap(int[] array, int l, int r) {
        int temp = array[r];
        array[r] = array[l];
        array[l] = temp;
    }
}
