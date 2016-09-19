class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        for(int i = 0;i < nums.size();i++){
            while( (nums[i]==2)&&(i<end)||(nums[i]==0)&&(i>start) ){
                if(nums[i]==2){
                    swap(nums[end--],nums[i]);
                }
                else{
                    swap(nums[start++],nums[i]);
                }
            }
        }
    }
};