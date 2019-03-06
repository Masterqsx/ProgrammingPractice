package algorithm.segment_tree;

public class MyZKWSegmentTree {
    private int[] tree;
    private int sz;
    private int m;

    private void build(int[] range) {
        //It has to be m <= sz, corner case is sz = 1
        for (m = 1; m <= sz; m <<= 1) ;
        //This is important since the last parent node will reach to 2(m - 1) + 1
        // , we need to make sure it is reached even it is not valid
        //Important corner case is when range is length 1 array
        tree = new int[m * 2 + 1]; // corner case is when sz is 7, this because our leaf node start at m + 1, we need an extra space for end of open range
        // The start of leaf node start at m + 1 is because our query use open range, we need to have an extra space for start of open range
        for (int i = m + 1; i <= m + sz; ++i) tree[i] = range[i - m - 1];
        //tree root on 1
        for (int i = m - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }

    public MyZKWSegmentTree(int[] range) {
        this.sz = range.length;
        build(range);
    }

    public void updateSingle(int index, int val) {
        int pos = index + m + 1;
        tree[pos] = val;
        for (pos >>= 1; pos > 0; pos >>= 1) tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }

    public int query(int start, int end) {
        //Obviously we can not search through all nodes in the range.
        //In each level, we have to check only the outer node.
        //If we don't expand the close range [L, R] to (L-1, R+1)
        //, if L is left child, we need to use its parent's value, this will make the logic complex in each level.
        //We hope in each level, we only need the values of this level to iterate.
        //If we expand to open range, we can make sure if L-1 is left child, we only need update its right brother
        //If we L-1 is right child, the right brother of its parent node will handle it.
        //In this way, levels are isolated.
        //Trick: start^end^1 check if they are brother nodes.
        //Trick: start^1 will return its brother under the same parent
        //Essentially in this way, we traverse all nodes which range is fully covered by the query range
        // Also, we can traverse all required sub ranges in queried range until left index meet right index (s and e are brother nodes)
        int res = 0;
        for (start += m, end += m + 2; (start^end^1) != 0; start >>= 1, end >>= 1) {
            if (start % 2 == 0) // if start is left child
                res += tree[start + 1];
            if (end % 2 != 0) // if end is right child
                res += tree[end - 1];
        }
        return res;
    }
}
