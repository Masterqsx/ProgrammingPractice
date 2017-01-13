class Solution {
public:
    int largestK(vector<int>& nums, int l, int h, int k) {
        if (l >= h) return nums[k];
        int i = l, m = l, j = h, pivot = nums[l];
        while (m <= j) {
            if (nums[m] > pivot) swap(nums[m++], nums[i++]);
            else if (nums[m] < pivot) swap(nums[m], nums[j--]);
            else m++;
        }
        if (k >= i && k <= j) return nums[j];
        else if (k > j) return largestK(nums, j+1, h, k);
        else return largestK(nums, l, i-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return largestK(nums, 0, nums.size()-1, k-1);
    }
};
