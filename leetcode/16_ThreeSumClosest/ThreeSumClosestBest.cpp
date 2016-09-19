class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int re = binarysearch(nums,target-nums[i],i+1)+nums[i];
            if(re==target) return target;
            if(result==INT_MAX){
                result=re;
            }
            else{
                result=abs(result-target)>abs(re-target)?re:result;
            }
        }
        return result;
        
    }
    
    int binarysearch(vector<int> nums, int target, int i){
        int lo = i;
        int hi = nums.size()-1;
        int result = INT_MAX;
        while(lo<hi){
            if(nums[lo]+nums[hi]<target){
                if(result==INT_MAX){
                    result=nums[lo]+nums[hi];
                }
                else{
                    result=abs(target-result)>abs(target-nums[lo]-nums[hi])?(nums[lo]+nums[hi]):result;
                }
                lo++;
            }
            else if(nums[lo]+nums[hi]>target){
                if(result==INT_MAX){
                    result=nums[lo]+nums[hi];
                }
                else{
                    result=abs(target-result)>abs(target-nums[lo]-nums[hi])?(nums[lo]+nums[hi]):result;
                }
                hi--;
            }
            else{
                return target;
            }
        }
        return result;
    }
};