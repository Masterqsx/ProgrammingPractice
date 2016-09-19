class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned int s_size = s.size(), p_size = p.size();
        vector<vector<bool> > dp = vector<vector<bool> >(s_size + 1, vector<bool>(p_size + 1, false));
        dp[0][0] = true;
        for (int i = 0;i < s_size + 1;i++){
            for (int j = 1;j < p_size + 1;j++){
                if (i == 0 && p[j - 1] == '*') dp[i][j] = dp[i][j - 1];
                else if(i == 0) dp[i][j] = false;
                else if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = false;
            }
        }
        return dp[s_size][p_size];
    }
};