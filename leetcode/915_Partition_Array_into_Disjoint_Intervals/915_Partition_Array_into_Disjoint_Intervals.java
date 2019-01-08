class Solution {
    public int partitionDisjoint(int[] A) {
        int[] r = new int[A.length];
        r[A.length - 1] = A[A.length - 1];
        for (int i = A.length - 2; i >= 0; i--) {
            r[i] = Math.min(A[i], r[i + 1]);
        }
        
        int lMax = A[0];
        for (int i = 1; i < A.length; i++) {
            if (lMax <= r[i]) return i;
            lMax = Math.max(lMax, A[i]);
        }
        return A.length;
    }
}
