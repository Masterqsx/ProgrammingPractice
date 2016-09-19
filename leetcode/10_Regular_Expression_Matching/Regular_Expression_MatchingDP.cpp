class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        bool dp[s_size+1][p_size+1];
        dp[0][0] = true;
        for(int j=1;j<p_size+1;j++){
            if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
            else  dp[0][j] = false;
        }
        for(int i=1;i<s_size+1;i++){
            for(int j=0;j<p_size+1;j++){
                if (j == 0) dp[i][j] = false;
                else if (s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*' && (s[i-1] == p[j-2] || p[j-2] == '.')) dp[i][j] = dp[i-1][j] || dp[i][j-2];//very important
                else if (p[j-1] == '*') dp[i][j] = dp[i][j-2];
                else dp[i][j] = false;
            }
        }
        return dp[s_size][p_size];
    }
};