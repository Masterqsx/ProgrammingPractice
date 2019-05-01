class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int sz = R * C;
        int[][] res = new int[sz][2];
        int idx = 0;
        for (int dis = 0;; dis++) {
            for (int i = 0; i <= dis; i++) {
                int rPlus = r0 + i, rMinus = r0 - i, cPlus = c0 + dis - i, cMinus = c0 - dis + i;
                if (rPlus >= 0 && rPlus < R) {
                    if (cPlus >= 0 && cPlus < C) {
                        res[idx][0] = rPlus;
                        res[idx++][1] = cPlus;
                    }
                    if (idx >= sz) break;
                    if (cMinus != cPlus && cMinus >= 0 && cMinus < C) {
                        res[idx][0] = rPlus;
                        res[idx++][1] = cMinus;
                    }
                    if (idx >= sz) break;
                }
                if (rMinus != rPlus && rMinus >= 0 && rMinus < R) {
                    if (cPlus >= 0 && cPlus < C) {
                        res[idx][0] = rMinus;
                        res[idx++][1] = cPlus;
                    }
                    if (idx >= sz) break;
                    if (cMinus != cPlus && cMinus >= 0 && cMinus < C) {
                        res[idx][0] = rMinus;
                        res[idx++][1] = cMinus;
                    }
                    if (idx >= sz) break;
                }
            }
            if (idx >= sz) break;
        }
        return res;
    }
}
