class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(i+1);
            sum-=nums[i];
        }
        return sum;
    }
};