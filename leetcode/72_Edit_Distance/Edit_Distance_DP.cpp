class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1_size = word1.size(), w2_size = word2.size();
        int dp[w1_size+1][w2_size+1] = {{0}};
        for(int j=1;j<w2_size+1;j++) dp[0][j] = j;
        for(int i=1;i<w1_size+1;i++){
            for(int j=0;j<w2_size+1;j++){
                if (j == 0) dp[i][0] = i;
                else if (word1[i-1] == word2[j-1]) dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]+1), dp[i][j-1]+1);
                else dp[i][j] = min(min(dp[i-1][j-1]+1, dp[i-1][j]+1), dp[i][j-1]+1);
            }
        }
        return dp[w1_size][w2_size];
    }
};