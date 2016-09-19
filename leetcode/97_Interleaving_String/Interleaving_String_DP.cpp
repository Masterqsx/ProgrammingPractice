class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        string ssum = s1 + s2, s3_temp(s3);
        sort(ssum.begin(), ssum.end());
        sort(s3_temp.begin(), s3_temp.end());
        if (ssum != s3_temp) return false;
        bool dp[s1.size()+1][s2.size()+1] = {{0}};
        dp[0][0] = true;
        for (int j=1;j<=s2.size();j++) dp[0][j] = (s3[j-1] == s2[j-1]) && dp[0][j-1];
        for (int i=1;i<=s1.size();i++){
            for (int j=0;j<=s2.size();j++){
                if (j == 0) dp[i][0] = (s3[i-1] == s1[i-1]) && dp[i-1][0];
                else dp[i][j] = (dp[i][j-1] && s3[i+j-1]==s2[j-1]) || (dp[i-1][j] && s3[i+j-1]==s1[i-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};