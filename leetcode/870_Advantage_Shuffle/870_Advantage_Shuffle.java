class Solution {
    private class ele {
        public int index;
        public int val;
        public ele(int index, int val) {
            this.index = index;
            this.val = val;
        }
    }
    public int[] advantageCount(int[] A, int[] B) {
        ArrayList<ele> sortedList = new ArrayList<>();
        ArrayList<Integer> shuffleList = new ArrayList<>();
        int[] res = new int[A.length];
        
        for (int i = 0; i < B.length; i++) {
            sortedList.add(new ele(i, B[i]));
            shuffleList.add(A[i]);
        }
        Collections.sort(sortedList, (e1, e2) -> e2.val - e1.val);
        Collections.sort(shuffleList, (e1, e2) -> e2 - e1);
        
        int iA = 0, iB = 0;
        while (iB < B.length) {
            if (shuffleList.get(iA) > sortedList.get(iB).val) {
                res[sortedList.get(iB).index] = shuffleList.get(iA);
                iA++;
            }
            iB++;
        }
        int i = 0;
        while (iA < A.length) {
            while(res[i] != 0) i++;
            res[i] = shuffleList.get(iA++);
        }
        return res;
    }
}
