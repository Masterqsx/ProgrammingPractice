package algorithm.segment_tree;

public class MyZKWQuadSegmentTree {
    private int[][] tree;
    private int column;
    private int row;
    private int mColumn;
    private int mRow;
    public MyZKWQuadSegmentTree(int[][] range) {
        column = range.length;
        if (range.length > 0) row = range[0].length;
        build(range);
    }

    private void build(int[][] range) {
        //It has to be m <= sz, corner case is sz = 1
        for (mColumn = 1; mColumn <= column; mColumn <<= 1) ;
        //It has to be m <= sz, corner case is sz = 1
        for (mRow = 1; mRow <= row; mRow <<= 1);
        tree = new int[2 * mColumn + 1][2 * mRow + 1];
        for (int i = mColumn + 1; i <= mColumn + column; ++i)
            for (int j = mRow + 1; j <= mRow + row; ++j)
                tree[i][j] = range[i - mColumn - 1][j - mRow - 1];

        //If one dimension is in range of parents, the other can also be leaf range
        //vector accumulation
        for (int i = mColumn + 1; i <= mColumn + column; ++i) {
            for (int j = mRow - 1; j > 0; --j) {
                tree[i][j] = tree[i][j << 1] + tree[i][j << 1 | 1];
            }
        }

        //If one dimension is in range of parents, the other can also be leaf range
        //vector accumulation
        for (int j = mRow + 1; j <= mRow + row; ++j) {
            for (int i = mColumn - 1; i > 0; --i) {
                tree[i][j] = tree[i << 1][j] + tree[i << 1 | 1][j];
            }
        }

        //square update
        for (int i = mColumn - 1; i > 0; --i) {
            for (int j = mRow - 1; j > 0; --j) {
                tree[i][j] = tree[i << 1][j << 1]
                    + tree[i << 1 | 1][j << 1]
                    + tree[i << 1][j << 1 | 1]
                    + tree[i << 1 | 1][j << 1 | 1];
            }
        }

    }

    public void updateSingle(int iColumn, int iRow, int val) {
        int posC = iColumn + mColumn + 1, posR = iRow + mRow + 1;
        tree[posC][posR] = val;

        //If one dimension is in range of parents, the other can also be leaf range
        //vector accumulation
        for (int i = posC >> 1; i > 0; i >>= 1) tree[i][posR] = tree[i << 1][posR] + tree[i << 1 | 1][posR];
        //If one dimension is in range of parents, the other can also be leaf range
        //vector accumulation
        for (int j = posR >> 1; j > 0; j >>= 1) tree[posC][j] = tree[posC][j << 1] + tree[posC][j << 1 | 1];

        for (int i = posC >> 1; i > 0; i >>= 1) {
            for (int j = posR >> 1; j > 0; j >>= 1) {
                tree[i][j] = tree[i << 1][j << 1]
                    + tree[i << 1 | 1][j << 1]
                    + tree[i << 1][j << 1 | 1]
                    + tree[i << 1 | 1][j << 1 | 1];
            }
        }
    }

    public int query(int sC, int eC, int sR, int eR) {
        int res = 0;
        for (int iS = sC + mColumn, iE = eC + mColumn + 2; (iS ^ iE ^ 1) != 0; iS >>= 1, iE >>= 1) {
            if (iS % 2 == 0) {
                //specific for 2D Segment Tree
                for (int jS = sR + mRow, jE = eR + mRow + 2; (jS ^ jE ^ 1) != 0; jS >>= 1, jE >>= 1) {
                    if (jS % 2 == 0) res += tree[iS^1][jS^1];
                    if (jE % 2 == 1) res += tree[iS^1][jE^1];
                }
            }
            if (iE % 2 == 1) {
                //specific for 2D Segment Tree
                for (int jS = sR + mRow, jE = eR + mRow + 2; (jS ^ jE ^ 1) != 0; jS >>= 1, jE >>= 1) {
                    if (jS % 2 == 0) res += tree[iE^1][jS^1];
                    if (jE % 2 == 1) res += tree[iE^1][jE^1];
                }
            }
        }
        return res;
    }
}
