class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++){
            int l = i + 1, r = nums.size()-1;
            while (l < r){
                if (nums[l] + nums[r] < target - nums[i]) {
                    count += r - l;
                    l++;
                }
                else if (nums[l] + nums[r] >= target - nums[i]) r--;
            }
        }
        return count;
    }
};
