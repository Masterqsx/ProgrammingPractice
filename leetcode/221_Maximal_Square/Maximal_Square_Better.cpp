class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int dp[2][matrix[0].size()] = {{0}};
        int len = matrix.size(), wid = matrix[0].size(), maximum = 0, cur = 0, pre = 0;
        for(int j=0;j<wid;j++){
            dp[0][j] = (matrix[0][j] == '1')?1:0;
            maximum = max(dp[0][j], maximum);
        }
        for(int i=1;i<len;i++){
            cur = i % 2;
            pre = 1 - cur;
            dp[cur][0] = (matrix[i][0] == '1')?1:0;
            maximum = max(dp[cur][0], maximum);
            for(int j=1;j<wid;j++){
                if (matrix[i][j] == '0') dp[cur][j] = 0;
                else{
                    dp[cur][j]=min(min(dp[cur][j-1], dp[pre][j]), dp[pre][j-1]) + 1;
                    maximum = max(dp[cur][j], maximum);
                }
            }
        }
        return maximum * maximum;
    }
};