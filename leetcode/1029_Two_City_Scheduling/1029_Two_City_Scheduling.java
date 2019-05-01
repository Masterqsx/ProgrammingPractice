class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int dp[][] = new int[costs.length + 1][costs.length + 1];
        dp[0][0] = costs[0][1];
        dp[0][1] = costs[0][0];
        for (int i = 1; i < costs.length; i++) {
            for (int j = 0; j <= i + 1; j++) {
                if (j == 0) dp[i][j] = dp[i - 1][j] + costs[i][1];
                else if (j == i + 1) dp[i][j] = dp[i - 1][j - 1] + costs[i][0];
                else dp[i][j] = Math.min(dp[i - 1][j] + costs[i][1], dp[i - 1][j - 1] + costs[i][0]);
            }
        }
        return dp[costs.length - 1][costs.length / 2];
    }
}
