class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            int mod = (k == 0 ? count : count % k);
            if (mod == 0 && i > 0) return true;
            if (check.find(mod) != check.end() && i - check[mod] > 1) return true;
            if (check.find(mod) == check.end()) check[mod] = i;
        }
        return false;
    }
};
