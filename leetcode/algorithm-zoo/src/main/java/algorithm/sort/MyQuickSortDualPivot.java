package algorithm.sort;

public class MyQuickSortDualPivot {
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void sort(int[] arr, int l, int r) {
        if (l >= r) return;
        int p1 = l, p2 = r, lt = l + 1, i = l + 1, gt = r - 1;
        //make sure pivot 1 is smaller than pivot 2
        if (arr[p1] > arr[p2]) swap(arr, p1, p2);
        while (i <= gt) {
            if (arr[i] > arr[p2]) swap(arr, i, gt--);
            else if (arr[i] < arr[p1]) swap(arr, i++, lt++);
            else i++;
        }
        swap(arr, p1, --lt);
        swap(arr, p2, ++gt);

        sort(arr, l, lt - 1);
        sort(arr, lt + 1, gt - 1);
        sort(arr, gt + 1, r);
    }
}
