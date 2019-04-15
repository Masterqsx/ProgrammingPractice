package algorithm.sort;

public class MyMergeSortBottomUp {
    public static void sort(int[] array) {
        for (int sz = 1; sz < array.length; sz *= 2) {
            for (int i = 0; i < array.length; i += 2 * sz) {
                int l = i, r = Math.min(array.length - 1, i + 2 * sz - 1);
                //The line below is very important
                //The first part has to be one full sz sector
                if (r - l + 1 <= sz) continue;

                int mid = i + sz - 1;
                int p = i, q = mid + 1, cur = 0;
                int[] temp = new int[r - l + 1];

                while (p <= mid && q <= r) {
                    if (array[p] < array[q]) temp[cur] = array[p++];
                    else temp[cur] = array[q++];
                    cur++;
                }
                while (p <= mid) temp[cur++] = array[p++];
                while (q <= r) temp[cur++] = array[q++];

                for (int k = 0; k < temp.length; k++) array[k + l] = temp[k];
            }
        }
    }
}
