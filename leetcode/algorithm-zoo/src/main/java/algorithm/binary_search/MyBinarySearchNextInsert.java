package algorithm.binary_search;


public class MyBinarySearchNextInsert {
    public static int search(int[] arr, int target) {
        int s = 0, e = arr.length - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= target) e = mid;
            else s = mid + 1;
        }
        if (arr[s] < target) return s + 1;
        else return s;
    }

}
