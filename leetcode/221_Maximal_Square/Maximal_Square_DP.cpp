class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int dp[matrix.size()][matrix[0].size()] = {{0}};
        int len = matrix.size(), wid = matrix[0].size(), maximum = 0;
        for(int j=0;j<wid;j++){
            dp[0][j] = (matrix[0][j] == '1')?1:0;
            maximum = max(dp[0][j], maximum);
        }
        for(int i=1;i<len;i++){
            dp[i][0] = (matrix[i][0] == '1')?1:0;
            maximum = max(dp[i][0], maximum);
        }
        for(int i=1;i<len;i++){
            for(int j=1;j<wid;j++){
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j]=min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                    maximum = max(dp[i][j], maximum);
                }
            }
        }
        return maximum * maximum;
    }
};