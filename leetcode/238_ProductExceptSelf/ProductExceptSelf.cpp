class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output=vector<int>(nums.size(),0);
        int product=1;
        for(int i=nums.size()-1;i>=0;i--){
            product*=nums[i];
            output[i]=product;
        }
        product=1;
        for(int i=0;i<nums.size()-1;i++){
            output[i]=output[i+1]*product;
            product*=nums[i];
        }
        output[nums.size()-1]=product;
        return output;
    }
};