class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp=vector<int>(nums);
        if(nums.size()<3) return nums.size();
        int len = 2;
        for(int i = 2;i<nums.size();i++){
            if(temp[i]!=temp[i-2]){
                nums[len++]=temp[i];
            }
        }
        return len;
    }
};