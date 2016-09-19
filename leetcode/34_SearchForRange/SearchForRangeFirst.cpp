class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> re;
        int lo=0;
        int hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi=mid;
            }
            if(nums[mid]<target){
                lo=mid+1;
            }
        }
        if(nums[hi]!=target){
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }
        else{
            re.push_back(hi);
        }
        lo=0;
        hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo+1)/2;
            if(nums[mid]>target){
                hi=mid-1;
            }
            if(nums[mid]<=target){
                lo=mid;
            }
        }
        re.push_back(lo);
        return re;
    }
};