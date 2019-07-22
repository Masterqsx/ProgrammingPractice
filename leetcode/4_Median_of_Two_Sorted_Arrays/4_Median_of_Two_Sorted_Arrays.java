class Solution {
    private int findKth(int[] nums1, int l1, int r1, int[] nums2, int l2, int r2, int k) {
        if (l1 > r1) return nums2[l2 + k - 1];
        if (l2 > r2) return nums1[l1 + k - 1];
        int mi1 = l1 + (r1 - l1) / 2;
        int mi2 = l2 + (r2 - l2) / 2;
        int len1 = mi1 - l1;
        int len2 = mi2 - l2;
        if (nums1[mi1] <= nums2[mi2]) {
            if (k <= len1 + len2 + 1) return findKth(nums1, l1, r1, nums2, l2, mi2 - 1, k);
            else return findKth(nums1, mi1 + 1, r1, nums2, l2, r2, k - len1 - 1);
        } else {
            if (k <= len1 + len2 + 1) return findKth(nums1, l1, mi1 - 1, nums2, l2, r2, k);
            else return findKth(nums1, l1, r1, nums2, mi2 + 1, r2, k - len2 - 1);
        }
    }
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int p1 = (nums1.length + nums2.length - 1) / 2;
        int p2 = (nums1.length + nums2.length) / 2;
        return (findKth(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, p1 + 1)
                + findKth(nums1, 0, nums1.length - 1, nums2, 0, nums2.length - 1, p2 + 1)) / 2.0;
    }
}
