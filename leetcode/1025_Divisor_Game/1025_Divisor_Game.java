class Solution {
    public boolean divisorGame(int N) {
        boolean[] dp = new boolean[1001];
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; i++) {
            for (int x = i - 1; x > 0; x--) {
                if (i % x == 0) dp[i] = dp[i] || !dp[i - x];
            }
        }
        return dp[N];
    }
}
