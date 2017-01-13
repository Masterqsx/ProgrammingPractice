class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 2 != 0) return false;
        return dfs(nums, nums.size(), sum/2);
    }
    bool dfs(vector<int>& nums, int cur, int target){
        if (target < 0) return false;
        if (target == 0) return true;
        for (int i = cur - 1; i >= 0 && nums[i] <= target;i--){
            if (dfs(nums, i, target - nums[i])) return true;
        }
        return false;
    }
};
