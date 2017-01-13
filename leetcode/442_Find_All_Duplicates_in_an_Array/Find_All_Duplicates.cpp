class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return vector<int>();
        int i = 0, sz = nums.size();
        unordered_set<int> dup;
        while (i < sz) {
            if (i != nums[i] - 1) {
                int target_index = nums[i] - 1;
                if (target_index == nums[target_index] - 1) {
                    dup.insert(nums[target_index]);
                    i++;
                }
                else swap(nums[i], nums[target_index]);
            }
            else i++;
        }
        return vector<int>(dup.begin(), dup.end());
    }
};
