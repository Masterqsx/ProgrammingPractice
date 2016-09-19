class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s;
        for (int i=0;i<nums.size();i++){
            if (s.empty() || nums[i] > s[s.size()-1]) s.push_back(nums[i]);
            else s[binarySearch(0, s.size()-1, s, nums[i])] = nums[i];
        }
        return s.size();
    }
    
    int binarySearch(int lo, int hi, vector<int> &s, int val){
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            if (s[mid] >= val) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};