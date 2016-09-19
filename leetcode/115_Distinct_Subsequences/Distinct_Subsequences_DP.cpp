class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        int dp[s.size()+1][t.size()+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if (j==0) dp[i][0] = 1;
                else{
                    if (j <= i && s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};