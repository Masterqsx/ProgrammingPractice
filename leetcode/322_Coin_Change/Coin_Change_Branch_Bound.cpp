class Solution {
public:
    int best = INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        dfs(coins, amount, coins.size()-1, 0);
        return best == INT_MAX?-1:best;
    }
    void dfs(vector<int>& coins, int amount, int item_id, int cur) {
        if (amount < 0) return;
        if (amount == 0) {
            best = min(best, cur);
            return;
        }
        if (item_id < 0) return;
        int n = amount / coins[item_id];
        if (cur + n > best) return;
        for (int i = n;i>=0;i--){
            dfs(coins, amount - i*coins[item_id], item_id-1, cur+i);
        }
    }
    
};
