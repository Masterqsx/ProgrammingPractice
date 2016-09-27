class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int dp[costs.size()][3] = {{costs[0][0], costs[0][1], costs[0][2]}};
        for (int i=1;i<costs.size();i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        return min(dp[costs.size()-1][0], min(dp[costs.size()-1][1], dp[costs.size()-1][2]));
    }
};
