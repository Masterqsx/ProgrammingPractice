class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int re = binarysearch(nums,target-nums[i]-nums[j],j+1)+nums[i]+nums[j];
                result=abs(result-target)>abs(re-target)?re:result;
            }
        }
        return result;
        
    }
    
    int binarysearch(vector<int> nums, int target, int i){
        int lo = i;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]<target){
                lo = mid + 1;
            }
            else if(nums[mid]>target){
                hi = mid;
            }
            else{
                return target;
            }
        }
        if(lo==i){
            return nums[lo];
        }
        else{
            return abs(target-nums[lo])>abs(target-nums[lo-1])?nums[lo-1]:nums[lo];
        }
    }
};