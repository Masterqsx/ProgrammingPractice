class Solution {
    private boolean isValid(int[][] matrix, int i, int j) {
        for (int x = 1; x < matrix[i].length; x++) {
            if ((matrix[i][x] ^ matrix[j][x]) != (matrix[i][x - 1] ^ matrix[j][x - 1])) return false;
        }
        return true;
    }
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        
        int res = -1;
        for (int i = 0; i < matrix.length; i++) {
            int dp = 0;
            for (int j = 0; j < matrix.length; j++) {
                if (isValid(matrix, i, j)) dp++;
            }
            if (dp > res) res = dp;
        }
        return res;
    }
}
