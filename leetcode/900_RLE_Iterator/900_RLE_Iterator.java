class RLEIterator {
    
    private List<Integer> numbers;
    
    private List<Integer> counts;
    
    private int i;
    
    private int j;
    
    public RLEIterator(int[] A) {
        numbers = new ArrayList<Integer>(A.length / 2);
        counts = new ArrayList<Integer>(A.length / 2);
        i = 0;
        j = 0;
        for (int i = 0; i < A.length; i+=2) {
            if (A[i] > 0) {
                numbers.add(A[i + 1]);
                counts.add(A[i]);
            }
        }
    }
    
    public int next(int n) {
        int res = -1;
        while (i < counts.size() && n > 0) {
            if (n >= counts.get(i) - j) {
                n -= (counts.get(i) - j);
                res = numbers.get(i);
                i += 1;
                j = 0;
            } else {
                res = numbers.get(i);
                j += n;
                n = 0;
            }
        }
        if (i < counts.size()) return res;
        else return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
