class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        if (nums.size() == 2) return nums[0];
        int slow = 0, fast = 0, n = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        while (n != slow){
            slow = nums[slow];
            n = nums[n];
        }
        return n;
    }
};