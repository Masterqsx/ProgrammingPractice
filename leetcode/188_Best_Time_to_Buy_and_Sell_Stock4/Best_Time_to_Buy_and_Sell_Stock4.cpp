class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) return 0;
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int cur[k+1];
        int ma[k+1] = {0};
        for (int m=0;m<=k;m++) cur[m] = INT_MIN;
        for (int i=0;i<prices.size();i++){
            for (int m=1;m<=k;m++){
                if (m==1)
                    cur[m] = max(cur[m], 0 - prices[i]);
                else
                    cur[m] = max(cur[m], ma[m-1] - prices[i]);
                ma[m] = max(ma[m], prices[i] + cur[m]);
            }
        }
        return ma[k];
    }
};