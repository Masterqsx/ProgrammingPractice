class Solution {
    public void bp(List<Integer> cur, List<List<Integer>> res, int k, int n, int start) {
        if (cur.size() == k) {
            ArrayList temp = new ArrayList<Integer>(cur);
            res.add(temp);
        }
        else {
            for (int i = start; i <= n; i++) {
                cur.add(i);
                bp(cur, res, k, n, i + 1);
                cur.remove(cur.size() - 1);
            }
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        bp(cur, res, k, n, 1);
        return res;
    }
}
