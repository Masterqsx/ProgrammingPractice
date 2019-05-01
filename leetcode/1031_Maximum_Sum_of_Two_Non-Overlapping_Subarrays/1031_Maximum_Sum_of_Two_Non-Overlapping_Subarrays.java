class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int[] AL = new int[A.length - L + 1];
        int[] AM = new int[A.length - M + 1];
        for (int i = 0; i < L; i++) AL[0] += A[i];
        for (int i = 1; i < AL.length; i++) AL[i] = AL[i - 1] - A[i - 1] + A[i + L - 1];
        for (int i = 0; i < M; i++) AM[0] += A[i];
        for (int i = 1; i < AM.length; i++) AM[i] = AM[i - 1] - A[i - 1] + A[i + M - 1];
        int res = 0;
        for (int i = 0; i < AL.length; i++) {
            int ie = i + L - 1;
            for (int j = 0; j < AM.length; j++) {
                int je = j + M - 1;
                if (je >= i && ie >= j) continue;
                else res = Math.max(res, AL[i] + AM[j]);
            }
        }
        return res;
    }
}
