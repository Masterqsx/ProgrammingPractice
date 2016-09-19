class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int b_dp[prices.size()] = {0}, s_dp[prices.size()] = {0};
        b_dp[0] = -prices[0];
        s_dp[0] = 0;
        for (int i=1;i<prices.size();i++){
            b_dp[i] = max(b_dp[i-1], (i<2?0:s_dp[i-2])-prices[i]);
            s_dp[i] = max(b_dp[i-1]+prices[i], s_dp[i-1]);
        }
        return max(b_dp[prices.size()-1], s_dp[prices.size()-1]);
    }
};
