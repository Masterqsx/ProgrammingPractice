class Solution {
public:
    int getMoneyAmount(int n) {
        if (n < 2) return 0;
        int dp[n][n] = {{0}};
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                dp[i][j] = i==j?0:INT_MAX;
            }
        }
        for (int step=1;step<n;step++) {
            for (int i=0;i<n-step;i++) {
                int j = i + step;
                for (int k=i;k<=j;k++) {
                    dp[i][j] = min((k+1 + max((k-1>i?dp[i][k-1]:0), (k+1<j?dp[k+1][j]:0))), dp[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
