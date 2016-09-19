class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        if (nums.size() == 2) return nums[0];
        int lo = 1, hi = nums.size() - 1;
        while (lo < hi){
            int mid = lo + (hi - lo) / 2, count = 0;
            for (int n : nums){
                if (n <= mid) count++;
            }
            if (count <= mid) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};