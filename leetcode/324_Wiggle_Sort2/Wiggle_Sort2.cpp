class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        sort(nums.begin(), nums.end());
        int start = (nums.size()+1) / 2-1, end = nums.size()-1;
        vector<int> temp = vector<int>(nums.size(), 0);
        for (int i = 0;i<nums.size();i++){
            temp[i] = (i%2==0?nums[start--]:nums[end--]);
        }
        nums.swap(temp);
    }
};
