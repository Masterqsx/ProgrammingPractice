package algorithm.sort;

public class MyQuickSort3Way {
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void sort(int[] arr, int l, int r) {
        if (l >= r) return;
        //We have to use a variable to store pivot value since there is no fixed pivot
        int lt = l, i = l, gt = r, v = l, p = arr[v];
        while (i <= gt) {
            if (arr[i] < p) swap(arr, i++, lt++);
            else if (arr[i] > p) swap(arr, i, gt--);
            else i++;
        }
        sort(arr, l, lt - 1);
        sort(arr, gt + 1, r);
    }
}
