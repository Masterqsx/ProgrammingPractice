class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(nums.size()==1){
            return nums[0]>=target?0:1;
        }
        int lo=0;
        int hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>target){
                hi=mid;
            }
            else if(nums[mid]<target){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        if(nums[hi]<target){
            return hi+1;
        }
        else{
            return hi;
        }
    }
};