class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()+1] = {0}, maximum = 0;
        for (int i=0;i<nums.size();i++){
            int j = i - 1, pre = 0;
            while (j >= 0){
                if (nums[j] < nums[i]) pre = max(pre, dp[j+1]);
                j--;
            }
            dp[i+1] = pre + 1;
            maximum = max(dp[i+1], maximum);
        }
        return maximum;
    }
};