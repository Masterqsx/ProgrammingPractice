class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int step=0;step<n;step++) {
            for (int i=1;i<=n;i++) {
                int j = i + step;
                if (j > n) break;
                for (int k=i;k<=j;k++) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + (k>i?dp[i][k-1]:0) + (k<j?dp[k+1][j]:0));
                }
            }
        }
        return dp[1][n];
    }
};
