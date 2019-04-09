package algorithm.sort;

public class TestSortUtility {
    public static int[] generateArray(int N) {
        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            res[i] = (int) (Math.random() * 2 * N - N);
        }

        return res;
    }
}
