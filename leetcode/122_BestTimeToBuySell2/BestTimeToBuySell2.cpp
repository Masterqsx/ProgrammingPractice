class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        if(prices.size()<2) return max;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i])
                max+=(prices[i+1]-prices[i]);
        }
        return max;
    }
};