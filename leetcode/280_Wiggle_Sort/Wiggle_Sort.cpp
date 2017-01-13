class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool flag = true;
        if (nums.size() < 2) return;
        for (int i=1;i<nums.size();i++){
            bool f = flag;
            int cur = i;
            while (cur > 0 && (f && nums[cur] < nums[cur-1] || !f && nums[cur] > nums[cur-1])){
                swap(nums[cur], nums[cur-1]);
                f = !f;
                cur--;
            }
            flag = !flag;
        }
    }
};
