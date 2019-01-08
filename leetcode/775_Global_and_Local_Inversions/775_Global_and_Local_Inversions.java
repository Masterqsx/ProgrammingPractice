class Solution {
    public boolean isIdealPermutation(int[] A) {
        for (int i = 0; i < A.length - 1; i++) {
            if (A[i] > A[i + 1]) {
                if (A[i] == A[i + 1] + 1 && A[i] == i + 1) continue;
                else return false;
            }
        }
        return true;
    }
}
