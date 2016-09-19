class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        if(nums.size()==2){
            swap(nums[0],nums[1]);
            return;
        }
        int j=0,i=0;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i!=-1){
            for(j=nums.size()-1;j>i;j--) {
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
        
    }
};