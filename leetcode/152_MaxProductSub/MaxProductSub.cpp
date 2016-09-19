class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxpre=nums[0],minpre=nums[0],maxcur=nums[0],mincur=nums[0],maxall=nums[0];
        for(int i=1;i<nums.size();i++){
            maxcur=max(maxpre*nums[i],max(minpre*nums[i],nums[i]));
            mincur=min(maxpre*nums[i],min(minpre*nums[i],nums[i]));
            maxall=max(max(maxcur,maxpre),maxall);
            maxpre=maxcur;
            minpre=mincur;
        }
        return maxall;
    }
};