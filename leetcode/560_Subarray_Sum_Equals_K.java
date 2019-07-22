class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> sum = new HashMap<>();
        sum.put(0, 1);
        int res = 0;
        for (int i = 0, c = 0; i < nums.length; i++) {
            c += nums[i];
            if (sum.containsKey(c - k)) res += sum.get(c - k);
            if (sum.containsKey(c)) sum.put(c, sum.get(c) + 1);
            else sum.put(c, 1);
        }
        return res;
    }
}
