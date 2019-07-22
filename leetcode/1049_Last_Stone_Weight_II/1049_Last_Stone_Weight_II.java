class Solution {
    public int lastStoneWeightII(int[] stones) {
        int[] dp = new int[3000];
        dp[0] = 1;
        int sumA = 0, res = Integer.MAX_VALUE;
        for (int a : stones) {
            sumA += a;
            for (int i = dp.length - 1; i >= a; --i)
                dp[i] |= dp[i - a];
        }
        for (int i = 1; i < dp.length; ++i)
            res = Math.min(res, Math.abs(sumA - dp[i] * i * 2));
        return res; 
    }
}
