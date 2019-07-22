class Solution {
    private int[] preColumnSum;
    private int res = 0;
    public void subarraySum(int[] cur, int target) {
        Map<Integer, Integer> sum = new HashMap<>();
        int curSum = 0;
        sum.put(0, 1);
        for (int i = 0; i < cur.length; i++) {
            curSum += cur[i];
            preColumnSum[i] += curSum;
            if (sum.containsKey(preColumnSum[i] - target)) res += sum.get(preColumnSum[i] - target);
            if (sum.containsKey(preColumnSum[i])) sum.put(preColumnSum[i], sum.get(preColumnSum[i]) + 1);
            else sum.put(preColumnSum[i], 1);       
        }
    }
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        for (int start = 0; start < matrix.length; start++) {
            preColumnSum = new int[matrix[0].length];
            for (int i = start; i < matrix.length; i++) subarraySum(matrix[i], target);
        }
        return res;
    }
}
