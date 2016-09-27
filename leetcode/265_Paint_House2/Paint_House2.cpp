class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int minCost = INT_MAX, n = costs.size(), k = costs[0].size();
        int dp[n][k];
        multiset<int> cur, next;
        for (int i=0;i<k;i++){
            dp[0][i] = costs[0][i];
            if (next.size() < 2) next.insert(dp[0][i]);
            else {
                next.insert(dp[0][i]);
                auto it = next.end();
                next.erase(--it);
            }
        }
        for (int i=1;i<n;i++){
            cur.swap(next);
            next.clear();
            for (int j=0;j<k;j++){
                dp[i][j] = (dp[i-1][j]==(*cur.begin())?(*(cur.rbegin())):(*cur.begin())) + costs[i][j];
                if (next.size() < 2) next.insert(dp[i][j]);
                else {
                    next.insert(dp[i][j]);
                    auto it = next.end();
                    next.erase(--it);
                }
            }
        }
        return *next.begin();
    }
};
