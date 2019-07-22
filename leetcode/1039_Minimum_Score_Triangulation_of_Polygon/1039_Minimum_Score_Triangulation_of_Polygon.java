class Solution {
    private int dfs(int[][] dp, int i, int j, int[] A) {
        if (j < i + 2) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        int res = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; k++) {
            res = Math.min(res, dfs(dp, i, k, A) + dfs(dp, k, j, A) + A[i] * A[k] * A[j]);
        }
        dp[i][j] = res;
        return res;
    }
    public int minScoreTriangulation(int[] A) {
        int[][] dp = new int[A.length][A.length];
        return dfs(dp, 0, A.length - 1, A);
    }
}
