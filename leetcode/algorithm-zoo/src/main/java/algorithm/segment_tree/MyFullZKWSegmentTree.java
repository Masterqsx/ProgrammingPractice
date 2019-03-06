package algorithm.segment_tree;

public class MyFullZKWSegmentTree {
    private int[] sum;
    private int[] tag;
    private int[] diff;
    private int m;

    public MyFullZKWSegmentTree(int[] range) {
        buildSumST(range);
        buildMaxST(range);
    }
    // Range Sum Segment Tree
    private void buildSumST(int[] range) {
        //It has to be m <= sz, corner case is sz = 1
        for (m = 1; m <= range.length; m <<= 1);
        sum = new int[2 * m + 1];
        tag = new int[2 * m + 1];
        for (int i = m + 1; i <= m + range.length; i++) sum[i] = range[i - m - 1];
        for (int i = m - 1; i > 0; --i) sum[i] = sum[i << 1] + sum[i << 1 | 1];
    }

    public void updateSingleSum(int index, int v) {
        int pos = index + m + 1;
        sum[pos] = v;
        for (pos >>= 1; pos > 0; pos >>= 1) sum[pos] = sum[pos << 1] + sum[pos << 1 | 1];
    }

    public void updateSum(int s, int e, int v) {
        //lc and rc is the index s and e traversed range inside update range
        int lc = 0, rc = 0, len = 1;
        for (s += m, e += m + 2; (s^e^1) != 0; s >>= 1, e >>= 1, len <<= 1) {
            //Cover the lowest sub ranges it traversed in tag
            //elements in tag array means all elements in range should modified value
            //The core idea is: the update tag will populate the nodes down until sub range is fully covered by update range.
            if (s % 2 == 0) {
                tag[s^1] += v;
                lc += len;
            }
            if (e % 2 == 1) {
                tag[e^1] += v;
                rc += len;
            }
            //The parent (range of node is not fully covered update range) it traversed also need to populate the modified value
            sum[s >> 1] += v * lc;
            sum[e >> 1] += v * rc;
        }
        //When meet the lowest common ancestor of update range, we also need to populate the sum
        for (lc += rc; s > 0; s >>= 1) sum[s >> 1] += v * lc;
    }

    public int querySum(int s, int e) {
        int lc = 0, rc = 0, len = 1, res = 0;
        for (s += m, e += m + 2; (s^e^1) > 0; s >>= 1, e >>= 1, len <<= 1) {
            //when query, the res should be sum value + tag value * len of node
            if (s % 2 == 0) {
                res += sum[s^1] + len * tag[s^1];
                lc += len;
            }
            if (e % 2 == 1) {
                res += sum[e^1] + len * tag[e^1];
                rc += len;
            }
        }
        //even we have traversed query range through left and right indices s and e, its ancestor could also have tag not populated below
        for (lc += rc; s > 0; s >>= 1) res += tag[s] * lc;
        return res;
    }

    // Range Max Segment Tree
    private void buildMaxST(int[] range) {
        for (m = 1; m <= range.length; m <<= 1);
        diff = new int[2 * m + 1];
        for (int i = m + 1; i <= m + range.length; i++) diff[i] = range[i - m - 1];
        //Assume it can only handle positive number
        //The diff array only store the difference value, the value of each node need accumulate from bottom to top
        for (int i = m - 1; i > 0; i--) {
            diff[i] = Math.max(diff[i << 1], diff[i << 1 | 1]);
            diff[i << 1] -= diff[i];
            diff[i << 1 | 1] -= diff[i];
        }
    }

    public void updateSingleMax(int index, int val) {
        //this val means we make node to val value not the difference
        int pos = index + m + 1;
        diff[pos] = val - diff[pos >> 1];
        for (pos >>= 1; pos > 0; pos >>= 1) {
            int temp = Math.max(diff[pos << 1], diff[pos << 1 | 1]);
            diff[pos] += temp;
            diff[pos << 1] -= temp;
            diff[pos << 1 | 1] -= temp;
        }
    }

    public void updateMax(int s, int e, int val) {
        for (s += m, e += m + 2; (s^e^1) != 0; s >>= 1, e >>= 1) {
            //If one node is fully covered by update range, update value
            if (s % 2 == 0) diff[s^1] += val;
            if (e % 2 == 0) diff[s^1] += val;

            //If one node is partially covered by update range or no intersect(the open range at the bottom)
            //The operation bellow is to update difference value
            //If the added value is not big enough to change the max value, the tempL is 0, add won't make any change
            //If the added value is larger than brother, the tempL is positive, we need to subtract tempL since in max tree
            // larger node will become 0 and the smaller node will become negative.
            int tempL = Math.max(diff[s], diff[s^1]);
            diff[s >> 1] += tempL;
            diff[s] -= tempL;
            diff[s^1] -= tempL;

            int tempR = Math.max(diff[e], diff[e^1]);
            diff[e >> 1] += tempR;
            diff[e] -= tempR;
            diff[e^1] -= tempR;
        }
        //When node's range covers update range
        for (;s > 0; s >>= 1) {
            int temp = Math.max(diff[s], diff[s^1]);
            diff[s >> 1] += temp;
            diff[s] -= temp;
            diff[s^1] -= temp;
        }
    }

    public int queryMax(int s, int e) {
        int L = 0, R = 0, res = 0;
        //Just in case s is always not brother of e
        if (s == e) {
            for (s += m + 1; s > 0; s >>= 1) res += diff[s];
            return res;
        }
        //We use close range here since it will add open range start and end's value
        //We can use open range but it will add more lines
        for (s += m + 1, e += m + 1; (s^e^1) != 0; s >>= 1, e >>= 1) {
            //If range of node traversed is partially covered by query range
            L += diff[s];
            R += diff[e];
            //If brother node is fully covered by query range
            if (s % 2 == 0) L = Math.max(L, diff[s^1]);
            if (e % 2 == 1) R = Math.max(R, diff[e^1]);
        }
        //When node's range covers query range
        for (res = Math.max(L, R), s >>= 1; s > 0; s >>= 1) res += diff[s];
        return res;
    }
}
