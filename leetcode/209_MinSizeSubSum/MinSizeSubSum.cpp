class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int start=0,end=0,minlength=INT_MAX,sum=0;
        for(end=0;end<nums.size();end++){
            sum+=nums[end];
            while(sum>=s){
                minlength=min(minlength,end-start+1);
                sum-=nums[start++];
            }
        }
        return minlength==INT_MAX?0:minlength;
    }
};