class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.first == rhs.first) return lhs.second > rhs.second;
            else return lhs.first < rhs.first;
        });
        vector<int> dp;
        for (int i=0;i<envelopes.size();i++) {
            if (dp.empty() || envelopes[i].second > dp.back()) dp.push_back(envelopes[i].second);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
                *it = envelopes[i].second;
            }
        }
        return dp.size();
    }
};
