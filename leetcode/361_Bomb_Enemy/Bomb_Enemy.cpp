class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size(), max_res = 0;
        vector<vector<pair<int, int>>> dp = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, {0, 0}));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j] != 'W'){
                    if (j == 0 || dp[i][j-1].first == -1){
                        for (int k=j;k<m;k++){
                            if (grid[i][k] == 'W') break;
                            if (grid[i][k] == 'E') dp[i][j].first++;
                        }
                    }
                    else dp[i][j].first = dp[i][j-1].first;
                    if (i == 0 || dp[i-1][j].second == -1){
                        for (int k=i;k<n;k++){
                            if (grid[k][j] == 'W') break;
                            if (grid[k][j] == 'E') dp[i][j].second++;
                        }
                    }
                    else dp[i][j].second = dp[i-1][j].second;
                }
                else dp[i][j] = pair<int, int>(-1, -1);
                if (grid[i][j] == '0') max_res = max(max_res, dp[i][j].first + dp[i][j].second);
            }
        }
        return max_res;
    }
};
