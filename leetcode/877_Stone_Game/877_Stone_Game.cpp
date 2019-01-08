class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int dp[piles.size()][piles.size()];
        memset(dp, 0, sizeof(dp[0][0]) * piles.size() * piles.size());
        for (int i = 0; i < piles.size() - 1; i++) {
            dp[i][i + 1] = max(piles[i], piles[i + 1]);
        }
        for (int sz = 3; sz < piles.size(); sz += 2) {
            for (int i = 0; i < piles.size() - sz; i++) {
                dp[i][i + sz] = max(
                                    max(dp[i + 2][i + sz] + piles[i] - piles[i + 1]
                                        , dp[i + 1][i + sz - 1] + piles[i] - piles[i + sz])
                                    ,
                                    max(dp[i][i + sz - 2] + piles[i + sz] - piles[i + sz - 1]
                                        , dp[i + 1][i + sz - 1] + piles[i + sz] - piles[i])
                                );
            }
        }
        return dp[0][piles.size() - 1] > 0;
    }
};
