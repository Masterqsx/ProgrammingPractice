class NumMatrix {
public:
    vector<vector<int>> dp;
    int h;
    int w;
    NumMatrix(vector<vector<int>> &matrix) {
        h = matrix.size();
        w = h > 0 ? matrix[0].size():0;
        if (h == 0 || w == 0) return;
        dp = vector<vector<int>> (h, vector<int>(w, 0));
        dp[h-1][w-1] = matrix[h-1][w-1];
        for (int i=h-1;i>=0;i--) {
            for (int j=w-1;j>=0;j--) {
                dp[i][j] = matrix[i][j] + (j+1>=w?0:dp[i][j+1]) + (i+1>=h?0:dp[i+1][j]) - ((i+1<h&&j+1<w)?dp[i+1][j+1]:0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row2 >= h || col1 < 0 || col2 >= w) return 0;
        return (dp[row1][col1] - (col2+1<w?dp[row1][col2+1]:0) - (row2+1<h?dp[row2+1][col1]:0) +  ((row2+1<h&&col2+1<w)?dp[row2+1][col2+1]:0));
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
