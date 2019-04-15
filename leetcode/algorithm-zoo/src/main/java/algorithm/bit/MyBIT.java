package algorithm.bit;

public class MyBIT {
    private int[] tree;

    public MyBIT(int[] arr) {
        tree = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) update(i, arr[i]);
    }

    public void update(int idx, int val) {
        //The line below transforms idx based on 1 to based on 0
        //The bit starts from 1, otherwise, idx & (-idx) won't work from the start
        //It is still a variant of a tree, each node still has a virtual neighbour node
        //The virtual neighbour node has the same size of cumulative sum range
        //The parent nodes will cover the range of children nodes
        //The virtual neighbour nodes share the same size of cumulative sum range, so its index is idx + lowbit
        //** All virtual neighbour nodes share the same idx as its parent nodes
        idx += 1;
        while (idx < tree.length) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    public int query(int idx) {
        //bit divided the cumulative sum into several non-overlap sectors
        //**important** The size of each sector is the least significant bit
        //tree[idx] stores the cumulative sum in range [idx - 2^lowbit + 1, idx]
        idx += 1;
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= (idx & (-idx));
        }
        return res;
    }
}
