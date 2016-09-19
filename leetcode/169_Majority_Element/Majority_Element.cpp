class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, nb = nums[0];
        for (int i=1;i<nums.size();i++){
            if (nums[i] != nb) count--;
            else count++;
            if (count <= 0){
                nb = nums[i];
                count = 1;
            }
        }
        return nb;
    }
};