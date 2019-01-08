class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        ArrayList<Integer> cur = new ArrayList<>();
        for (int i = 0; i <= k; i++) cur.add(0);
        int i = 0;
        while (i >= 0 ) {
            if (i == k) {
                res.add(new ArrayList<Integer>(cur.subList(0, k)));
                i--;
            } else if (cur.get(i) >= n) {
                cur.set(i, 0);
                i--;
            } else {
                cur.set(i, cur.get(i) + 1);
                cur.set(i + 1, cur.get(i));
                i++;
            }
        }
        return res;
    }
}
