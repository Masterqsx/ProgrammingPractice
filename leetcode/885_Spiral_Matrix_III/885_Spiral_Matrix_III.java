class Solution {
    //int[0]: r, int[1]: c, int[2]: length, int[3]: direct
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int[] move = {r0, c0, 1, 1};
        int[][] res = new int[R * C][2];
        int i = 0;
        while (i < R * C) {
            int j = 0;
            while (j < 2 * move[2]) {
                if (move[0] >= 0 && move[0] < R && move[1] >=0 && move[1] < C) {
                    res[i][0] = move[0];
                    res[i][1] = move[1];
                    i++;
                }
                if (j < move[2]) move[1] += move[3];
                else move[0] += move[3];
                j++;
            }
            move[2] += 1;
            move[3] *= -1;
        }
        return res;
    }
}
