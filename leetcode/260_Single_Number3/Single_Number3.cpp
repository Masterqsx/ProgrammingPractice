class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() < 4) return nums; //prevent only two distinct elements
        int xor_value = 0;
        for (int n : nums) xor_value ^= n;
        int rightmost = xor_value & (-xor_value);//find the pos of rightmost set bit
        vector<int> res({0, 0});
        for (int n: nums){
            if ((n & rightmost) == 0) res[0] ^= n; //depending on the rightmost different bit, seperate into different group
            else res[1] ^= n;
        }
        return res;
    }
};