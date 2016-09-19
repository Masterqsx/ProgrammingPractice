class Solution {
public:
    int numSquares(int n) {
        if (n < 0) return 0;
        int dp[n+1];
        fill_n(dp, n+1, INT_MAX);
        dp[0] = 0;
        int i=0;
        for (i=0;i*i<=n;i++){
            for (int j=i*i;j<=n;j++){
                dp[j] = min(dp[j], dp[j-i*i]==INT_MAX?dp[j]:dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};