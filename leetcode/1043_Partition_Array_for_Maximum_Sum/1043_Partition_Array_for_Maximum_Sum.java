class Solution {
    public int[] dp;
    public int dfs(int s, int e, int[] A, int K) {
        if (s > e) return 0;
        if (s == e) {
            dp[s] = A[s];
            return A[s];
        }
        int maInSub = Integer.MIN_VALUE;
        int res = Integer.MIN_VALUE;
        for (int i = s; i < s + K && i <= e; i++) {
            if (A[i] > maInSub) maInSub = A[i];
            int cur = maInSub * (i - s + 1);
            if (dp[i + 1] == 0) dp[i + 1] = dfs(i + 1, e, A, K);
            cur += dp[i + 1];
            res = Math.max(res, cur);
        }
        return res;
    }
    public int maxSumAfterPartitioning(int[] A, int K) {
        dp = new int[A.length + 1];
        return dfs(0, A.length - 1, A, K);
    }
}
