class Solution {
public:
    void q_select(vector<int>& nums, int lo, int hi, int k){
        if (lo >= hi) return;
        int l = lo, r = hi, m = lo, target = nums[lo];
        while (m <= r){
            if (nums[m] < target) swap(nums[m++], nums[l++]);
            else if (nums[m] > target) swap(nums[m], nums[r--]);
            else m++;
        }
        if (k > l-1 && k < r+1) return;
        else if (k >= r+1) q_select(nums, r+1, hi, k);
        else q_select(nums, lo, l-1, k);
    }
    int trans(int index, int median, int hi){
        if (index <= median) return 2*(median-index);
        else return 2*(hi-index)+1;
    }
    void virtualspace_3waypartition(vector<int>& nums, int median){
        int l = 0, r = nums.size()-1, m = 0, target = nums[median], hi = nums.size()-1;
        while (m <= r){
            if (nums[trans(m, median, hi)] < target) swap(nums[trans(m++, median, hi)], nums[trans(l++, median, hi)]);
            else if (nums[trans(m, median, hi)] > target) swap(nums[trans(m, median, hi)], nums[trans(r--, median, hi)]);
            else m++;
        }
    }
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        q_select(nums, 0, nums.size()-1, (nums.size()-1)/2);
        virtualspace_3waypartition(nums, (nums.size()-1)/2);
    }
};
