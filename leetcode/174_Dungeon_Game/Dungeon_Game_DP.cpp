class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 1;
        int dp[dungeon.size()+1][dungeon[0].size()+1] = {{0}};
        for (int i=0;i<dungeon.size()-1;i++) dp[i][dungeon[0].size()] = INT_MAX;
        for (int j=0;j<dungeon[0].size()-1;j++) dp[dungeon.size()][j] = INT_MAX;
        dp[dungeon.size()][dungeon[0].size()-1] = 1;
        dp[dungeon.size()-1][dungeon[0].size()] = 1;
        for (int i=dungeon.size()-1;i>=0;i--){
            for (int j=dungeon[0].size()-1;j>=0;j--){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                if (dp[i][j] < 1) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
};