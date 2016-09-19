class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ma = nums[0];
        for(int i = 0;i < nums.size();i++){
            ma = max(nums[i]+i,ma);
            if(ma >= nums.size()-1){
                return true;
            }
            if(ma <= i){
                return false;
            }
        }
        return true;
    }
};