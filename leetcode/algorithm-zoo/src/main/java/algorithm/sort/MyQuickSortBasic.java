package algorithm.sort;

public class MyQuickSortBasic {
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void sort(int[] arr, int l, int r) {
        if (l >= r) return;
        int i = l + 1, j = r, p = l;
        while (true) {
            //any element before i is not greater than v
            while (arr[i] <= arr[p] && i < r) i++;
            //any element after j is not smaller than v
            while (arr[j] >= arr[p] && j > l) j--;
            //j will stop at location >= i - 1
            if (i >= j) break;
            swap(arr, i, j);
        }
        //*****Remember this has to be j not i
        //This is all because i traverse earlier than j
        //If i == j no difference
        //If j left beside i, i stopped because i > v (if i stopped because i == r, j should == i
        //But j stopped at left of i, j <= v
        //In order to maintain constrain, p should be swapped with j
        swap(arr, p, j);
        sort(arr, l, j - 1);
        sort(arr,  j + 1, r);
    }
}
