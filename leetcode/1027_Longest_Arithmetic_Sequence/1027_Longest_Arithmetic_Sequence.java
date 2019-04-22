class Solution {
    public int longestArithSeqLength(int[] A) {
        int res = 2;
        List<Map<Integer, Integer>> check = new ArrayList<>();
        check.add(new HashMap<Integer, Integer>());
        for (int i = 1; i < A.length; i++) {
            check.add(new HashMap<Integer, Integer>());
            for (int j = 0; j < i; j++) {
                int dif = A[i] - A[j];
                if (check.get(j).containsKey(dif)) {
                    check.get(i).put(dif, check.get(j).get(dif) + 1);
                    res = Math.max(res, check.get(i).get(dif));
                }
                else check.get(i).put(dif, 2);
            }
        }
        return res;
    }
}
