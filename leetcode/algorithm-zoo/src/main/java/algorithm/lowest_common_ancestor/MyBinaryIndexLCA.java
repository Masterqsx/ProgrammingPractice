package algorithm.lowest_common_ancestor;

import utility.Node;

import java.util.HashMap;
import java.util.Map;

public class MyBinaryIndexLCA {

    private Map<Integer, Integer> depth;

    private Map<Integer, Map<Integer, Integer>> binaryIdx;

    private void dfs(Node root, int d) {
        if (root == null) return;
        depth.put(root.val, d);
        if (root.left != null) {
            if (!binaryIdx.containsKey(root.left.val)) binaryIdx.put(root.left.val, new HashMap<>());
            binaryIdx.get(root.left.val).put(0, root.val);
            dfs(root.left, d + 1);
        }
        if (root.right != null) {
            if (!binaryIdx.containsKey(root.right.val)) binaryIdx.put(root.right.val, new HashMap<>());
            binaryIdx.get(root.right.val).put(0, root.val);
            dfs(root.right, d + 1);
        }
    }

    public MyBinaryIndexLCA(Node root) {
        depth = new HashMap<>();
        binaryIdx = new HashMap<>();
        dfs(root, 0);
        //The root node need to be added to binaryIdx outside hte dfs
        if (root != null) {
            binaryIdx.put(root.val, new HashMap<>());
            binaryIdx.get(root.val).put(0, root.val);
        }
        int maxDepth = 0, m = 1;
        for (Map.Entry<Integer, Integer> entry : depth.entrySet()) {
            maxDepth = Math.max(maxDepth, entry.getValue());
        }
        //In dfs we only set the parent and child binary idx
        //Here we use binaryIdx[idx][j] = binaryIdx[binaryIdx[idx][j - 1]][j - 1] to fill the rest
        for (;m <= maxDepth; m <<= 1) ;
        for (Map.Entry<Integer, Integer> entry : depth.entrySet()) {
            for (int j = 1; j <= m; j++) {
                binaryIdx.get(entry.getKey()).put(j, binaryIdx.get(binaryIdx.get(entry.getKey()).get(j - 1)).get(j - 1));
            }
        }
    }

    public int lca(int x, int y) {
        //x will be set to the deeper one
        if (depth.get(x) < depth.get(y)) {
            int temp = x;
            x = y;
            y = temp;
        }
        int m = 0;
        //Find the smallest power of 2 which is larger than depth of deeper node
        for (int d = 1; d <= depth.get(x); m++, d <<= 1) ;
        //Shift the deeper node to the same level as shallower node, try all kind the power of 2 in descending, has to be descending
        for (int j = (1 << m), i = m; j >= 1; i--, j >>= 1) {
            if (depth.get(x) - j >= depth.get(y)) x = binaryIdx.get(x).get(i);
        }
        if (x == y) return x;
        for (int j = (1 << m), i = m; j >= 1; i--, j >>= 1) {
            //shift the x and y up to the nodes right below lca
            //If they are already at the lca (same node), won't change
            if (binaryIdx.get(x).get(i) != binaryIdx.get(y).get(i)) {
                x = binaryIdx.get(x).get(i);
                y = binaryIdx.get(y).get(i);
            }
        }
        return binaryIdx.get(x).get(0);
    }
}
