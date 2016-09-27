class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        int dp[envelopes.size()] = {0};
        fill_n(dp, envelopes.size(), 1);
        int max_l = 1;
        for (int i=0;i<envelopes.size();i++) {
            for (int j=0;j<i;j++) {
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) dp[i] = max(dp[i], dp[j]+1);
            }
            max_l = max(max_l, dp[i]);
        }
        return max_l;
    }
};
