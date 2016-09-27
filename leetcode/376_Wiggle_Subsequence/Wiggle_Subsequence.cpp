class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int dp[nums.size()][2];
        for (int i=0;i<nums.size();i++) dp[i][1] = dp[i][0] = 1;
        for (int i=0;i<nums.size();i++) {
            for (int j=0;j<i;j++) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
                else if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
