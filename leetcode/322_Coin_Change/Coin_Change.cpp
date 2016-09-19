class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unsigned int num[(unsigned int)amount+1] = {0};
        fill_n(num, (unsigned int)amount+1, INT_MAX);
        num[0] = 0;
        for (unsigned int i=0;i<coins.size();i++) {
            for (unsigned int j=coins[i];j<=amount;j++) {
                if (j >= coins[i])
                    num[j] = min(num[j], num[j-coins[i]] == INT_MAX?INT_MAX:num[j-coins[i]]+1);
            }
        }
        return num[amount] == INT_MAX?-1:num[amount];
    }
};
