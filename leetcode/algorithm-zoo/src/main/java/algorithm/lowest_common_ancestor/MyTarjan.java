package algorithm.lowest_common_ancestor;

import utility.Node;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class MyTarjan {
    private Map<Integer, Integer> idx;

    private Map<Integer, Set<Integer>> pairs;

    private Map<Integer, Set<Integer>> buildPairs(int[][] querys) {
        Map<Integer, Set<Integer>> res = new HashMap<>();
        for (int i = 0; i < querys.length; i++) {
            if (!res.containsKey(querys[i][0])) res.put(querys[i][0], new HashSet<>());
            if (!res.containsKey(querys[i][1])) res.put(querys[i][1], new HashSet<>());
            res.get(querys[i][0]).add(querys[i][1]);
            res.get(querys[i][1]).add(querys[i][0]);
        }

        return res;
    }

    private void initializeUnionFind(Node root) {
        if (root == null) return;
        idx.put(root.val, root.val);
        if (!pairs.containsKey(root.val)) pairs.put(root.val, new HashSet<>());
        initializeUnionFind(root.left);
        initializeUnionFind(root.right);
    }

    private int find(int i) {
        while (idx.get(i) != i) {
            idx.put(i, idx.get(idx.get(i)));
            i = idx.get(i);
        }
        return i;
    }

    private void union(int parent, int child) {
        // The child node can only be merged to parent node
        // So we won't need to use weighted approach
        // Since we assume the query are much more than the # of nodes, each node will only be compressed once
        int iP = find(parent);
        idx.put(child, iP);
    }

    private void dfs(List<int[]> res, Node root, Set<Integer> visited) {
        if (root == null) return;
        //Adding to visited has to be at the top in order to handle query self with self case
        visited.add(root.val);
        //This is the only part for Tarjan, return results with the root of union-find
        //This trick is determined by the feature of DFS traversal in tree
        for (Integer to : pairs.get(root.val)) {
            if (visited.contains(to)) res.add(new int[]{root.val, to, find(to)});
        }
        dfs(res, root.left, visited);
        if (root.left != null) union(root.val, root.left.val);
        dfs(res, root.right, visited);
        if (root.right != null) union(root.val, root.right.val);
    }
    // The Node pointers are only for dfs
    // in union-find or check visited or check query pairs
    // the unique index of each node are used
    // In this implementation we assume the value in each node is unique
    // This is for offline query which means the query must come out once
    public List<int[]> lca(Node root, int[][] querys) {
        idx = new HashMap<>();
        pairs = buildPairs(querys);
        initializeUnionFind(root);

        List<int[]> res = new ArrayList<>();

        dfs(res, root, new HashSet<>());
        return res;
    }

}
