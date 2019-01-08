class Solution {
    void nToL(int num, List<Integer> res) {
        if (num / 10 > 0) nToL(num / 10, res);
        res.add(num % 10);
    }
    public int maximumSwap(int num) {
        List<List<Integer>> bucket = new ArrayList<>();
        for (int i = 0; i < 10; i++) bucket.add(new ArrayList<Integer>());
        
        ArrayList<Integer> numList = new ArrayList<>();
        nToL(num, numList);
        for (int i = numList.size() - 1; i >= 0; i--) {
            bucket.get(numList.get(i)).add(i);
        }
        
        for (int i = 0; i < numList.size(); i++) {
            int j = 9;
            for (; j > 0; j--) {
                if (numList.get(i) < j && bucket.get(j).size() > 0 && bucket.get(j).get(0) > i) break;
            }
            if (j != 0) {
                int temp = numList.get(i);
                numList.set((bucket.get(j).get(0)), numList.get(i));
                numList.set(i, j);
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < numList.size(); i++) {
            res = res * 10 + numList.get(i);
        }
        return res;
    }
}
