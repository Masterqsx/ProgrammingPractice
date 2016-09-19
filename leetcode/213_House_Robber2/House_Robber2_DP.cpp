class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int dp[nums.size()] = {0}, res = 0;;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        if (nums.size() == 2) return dp[1];
        dp[1] = nums[0];
        for (int i=2;i<nums.size()-1;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        res = dp[nums.size() - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(res, dp[nums.size()-1]);
    }
};