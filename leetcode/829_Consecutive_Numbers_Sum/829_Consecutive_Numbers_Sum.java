class Solution {
    public int consecutiveNumbersSum(int N) {
        int end = (int)Math.sqrt(2 * N);
        int count = 0;
        for (int n = 1; n <= end; n++) {
            if (2 * N % n == 0 && (2 * N / n - n + 1) > 0 && (2 * N / n - n + 1) % 2 == 0) count++;
        }
        return count;
    }
}
