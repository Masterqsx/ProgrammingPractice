class Solution {
public:
    vector<int> array;
    Solution(vector<int> nums) {
        array = vector<int>(nums);
        srand(time(0));
    }
    
    int pick(int target) {    
        int remaining = 0, res = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == target) {
                remaining++;
                if (rand() % remaining < 1) res = i; 
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
