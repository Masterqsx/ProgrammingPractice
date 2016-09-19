class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int ma0 = 0, ma1 = 0, cur_min = prices[0], cur_max = -prices[0];
        for (int i=0;i<prices.size();i++){
            ma0 = max(ma0, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
            cur_max = max(cur_max, ma0 - prices[i]);
            ma1 = max(ma1, cur_max + prices[i]);
        }
        return ma1;
    }
};