class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int ma = 0, cur_min = prices[0];
        for (int i=0;i<prices.size();i++){
            ma = max(ma, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        return ma;
    }
};