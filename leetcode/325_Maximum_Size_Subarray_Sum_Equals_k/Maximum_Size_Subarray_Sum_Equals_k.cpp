class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> m;
        int sum = 0, res = 0;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (sum == k) res = max(res, i+1);
            else if (m.count(sum-k) == 1) res = max(res, i-m[sum-k]);
            if (m.count(sum) == 0) m[sum] = i;
        }
        return res;
    }
};
