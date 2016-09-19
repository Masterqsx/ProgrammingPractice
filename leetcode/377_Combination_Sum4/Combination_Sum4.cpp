class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp({1});
        int count = 0;
        for (int i=1;i<=target;i++){
            count = 0;
            for (int j : nums){
                if (i - j < 0 || i - j >= i) continue;
                count += dp[i-j];
            }
            dp.push_back(count);
        }
        return dp.back();
    }
};