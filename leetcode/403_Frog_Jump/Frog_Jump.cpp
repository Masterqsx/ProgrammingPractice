class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2) return false;
        vector<unordered_set<int>> dp = vector<unordered_set<int>>(stones.size(), unordered_set<int>());
        dp[0].insert(0);
        for (int i=1;i<stones.size();i++){
            for (int j=i-1;j>=(i-1)/2;j--){
                if (dp[j].count(stones[i]-stones[j]) || dp[j].count(stones[i]-stones[j]+1) || dp[j].count(stones[i]-stones[j]-1)) dp[i].insert(stones[i]-stones[j]);
            }
        }
        return !dp[stones.size()-1].empty();
    }
};
