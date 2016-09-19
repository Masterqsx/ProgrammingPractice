class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned int s_size = s.size() + 1, p_size = p.size() + 1, cur = 0, pre = 0;
        bool dp[2][p_size];
        for (int i = 0;i < s_size;i++){
            cur = i % 2;
            pre = 1 - cur;
            for (int j = 0;j < p_size;j++){
                if (i == 0 && j == 0) dp[0][0] = true;
                else if (j == 0) dp[cur][0] = false;
                else if (i == 0 && p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
                else if(i == 0) dp[0][j] = false;
                else if (p[j - 1] == '*') dp[cur][j] = dp[pre][j] || dp[cur][j - 1];
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[cur][j] = dp[pre][j - 1];
                else dp[cur][j] = false;
            }
        }
        return dp[(s_size - 1) % 2][p_size - 1];
    }
};