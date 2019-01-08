class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int lo = 0, hi = nums[nums.length - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0, maxDist = 0;
            for(int start = 0, end = 0; end < nums.length; end++) {
                while(nums[end] - nums[start] > mid) start++;
                count += end - start;
                maxDist = Math.max(maxDist, nums[end] - nums[start]);
            }
            if (count == k) return maxDist;
            else if (count > k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    
}
