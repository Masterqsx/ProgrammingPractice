class Solution {
    private int[] tree;
    private int m;
    private void build(int[] nums) {
        for (m = 1; m <= nums.length; m <<= 1);
        tree = new int[2 * m];
        for (int i = m + 1; i <= m + nums.length; i++) tree[i] = 0;
    }
    private void update(int index) {
        int pos = index + m + 1;
        tree[pos] += 1;
        for (pos >>= 1; pos > 0; pos >>= 1) tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }
    private int query(int s, int e) {
        int res = 0;
        for (s += m, e += m + 2; (s^e^1) != 0; s >>= 1, e >>= 1) {
            if (s % 2 == 0) res += tree[s + 1];
            if (e % 2 == 1) res += tree[e - 1];
        }
        return res;
    }
    public int reversePairs(int[] nums) {
        build(nums);
        long[] numsSorted = new long[nums.length];
        for (int i = 0; i < nums.length; i++) numsSorted[i] = nums[i];
        Arrays.sort(numsSorted);
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int pos = Arrays.binarySearch(numsSorted, nums[i] * 2L + 1L);
            if (pos < 0) pos = -1 * (pos + 1);
            res += query(pos, nums.length - 1);
            update(Arrays.binarySearch(numsSorted, nums[i]));
        }
        return res;
    }
}
