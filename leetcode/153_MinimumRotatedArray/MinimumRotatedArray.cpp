class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        if(nums[lo]<=nums[hi]) return nums[lo];
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<nums[mid]){
                lo=mid;
            }
            else if(nums[lo]>nums[mid]){
                hi=mid;
            }
            else{
                return nums[lo+1];
            }
        }
    }
};