class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int dp[n] = {0};
        dp[0] = 10;
        for (int i=1;i<n;i++){
            int nb = 9;
            for (int j=0;j<i;j++) nb *= (9-j);
            dp[i] = nb + dp[i-1];
        }
        return dp[n-1];
    }
};