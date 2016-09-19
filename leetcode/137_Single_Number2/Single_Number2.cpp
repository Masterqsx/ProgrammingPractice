class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (int i=0;i<sizeof(int)*8;i++){
            int count = 0;
            for (int n : nums){
                if (((unsigned int)n & (1<<i)) > 0) count++;
            }
            if (count % 3 != 0) r |= 1 << i;
        }
        return r;
    }
};