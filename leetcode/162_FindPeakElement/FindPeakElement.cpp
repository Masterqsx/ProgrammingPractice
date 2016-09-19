class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if((nums[mid]>nums[mid+1])&&(nums[mid]>nums[mid-1])){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return 0;
    }
};