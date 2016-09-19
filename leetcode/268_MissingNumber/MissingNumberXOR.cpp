class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int re=nums.size();
        for(int i=0;i<nums.size();i++){
            re^=i;
            re^=nums[i];
        }
        return re;
    }
};