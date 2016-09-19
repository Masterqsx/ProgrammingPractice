class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cumax=nums[0];
        int wholemax=nums[0];
        for(int i=1;i<nums.size();i++){
            cumax=max(cumax+nums[i],nums[i]);//if cumax>0,keep adding,because wholemax already record the biggest sum this set have reached.if cuman<0, start a new set
            wholemax=max(cumax,wholemax);
        }
        return wholemax;
    }
    
};