package algorithm.graph;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MyChuLiu {
    public static class Edge {
        public String from;
        public String to;
        public int fromId;
        public int toId;
        public double weight;
        public Edge (String from, String to, int fromId, int toId, double weight) {
            this.from = from;
            this.to = to;
            this.fromId = fromId;
            this.toId = toId;
            this.weight = weight;
        }
    }

    private List<Edge> edges;

    private int n;

    public Map<String, String> prePath = new HashMap<>();

    private int rootId;

    public MyChuLiu(Map<String, Map<String, Double>> graph, String root) {
        //transform adjacent list to edges list
        //transform String id to integer id
        //record # of nodes and root node integer id
        edges = new ArrayList<>();
        Map<String, Integer> checked = new HashMap<>();
        int id = 0;

        for (Map.Entry<String, Map<String, Double>> entryI : graph.entrySet()) {
            for (Map.Entry<String, Double> entryJ : graph.get(entryI.getKey()).entrySet()) {
                if (!checked.containsKey(entryI.getKey())) {
                    checked.put(entryI.getKey(), id++);
                    prePath.put(entryI.getKey(), entryI.getKey());
                }
                if (!checked.containsKey(entryJ.getKey())) {
                    checked.put(entryJ.getKey(), id++);
                    prePath.put(entryJ.getKey(), entryJ.getKey());
                }
                edges.add(new Edge(entryI.getKey(), entryJ.getKey(), checked.get(entryI.getKey()), checked.get(entryJ.getKey()), entryJ.getValue()));
            }
        }
        n = checked.size();
        rootId = checked.get(root);
    }

    public double minMstWeight = 0.0;

    public boolean getResult() {
        //node id starts from 0
        int[] id = new int[n];
        double[] minCost = new double[n];
        int[] marked = new int[n];
        int[] pre = new int[n];
        while (true) {
            initialize(id, minCost, marked, pre);
            getMinCost(minCost, pre);
            if (!isReachable(minCost)) return false;
            int newN = getLoopNodes(id, marked, pre);
            if (newN == 0) return true;
            reconstructGraph(id, minCost, newN);
        }
    }

    private void initialize(int[] id, double[] minCost, int[] marked, int[] pre) {
        for (int i = 0; i < n; i++) {
            id[i] = -1;
            minCost[i] = Double.MAX_VALUE;
            marked[i] = -1;
            pre[i] = -1;
        }
    }

    private void getMinCost(double[] minCost, int[] pre) {
        //find minimum input path for each node and record predecessor for loop detect
        //record real predecessor path for result
        //handle root node
        for (Edge e : edges) {
            if (e.weight < minCost[e.toId] && e.toId != rootId) {
                minCost[e.toId] = e.weight;
                pre[e.toId] = e.fromId;
                prePath.put(e.to, e.from);
            }
        }
        //make sure root is always valid for reachable check
        minCost[rootId] = 0.0;
        pre[rootId] = rootId;
    }

    private boolean isReachable(double[] minCost) {
        for (int i = 0; i < n; i++) {
            if (minCost[i] == Double.MAX_VALUE) return false;
            minMstWeight += minCost[i];

        }
        return true;
    }

    private int getLoopNodes(int[] id, int[] marked, int[] pre) {
        //for each unmarked node, search until has no pre or the start node
        //give nodes in loops the same new ids
        //sequentially assign new ids to the nodes not in loops
        int newId = 0;
        for (int i = 0; i < n; i++) {
            int cur = i;
            while (marked[cur] == -1) {
            //This line is how to detect loop. marked array records the start node id
            //If the node is not in the loop, cur will be set to a node marked[cur] != -1 and start node is not i
            //If the node is in the loop, it will go back to itself and marked all nodes in the loop then there is no further traverse
            //Since each node only have one incoming path, so the start of dfs will be in the loop which is different from normal cycle detect
                marked[cur] = i;
                cur = pre[cur];
            }
            //root is also a small self loop
            if (cur == rootId || marked[cur] != i) continue;
            id[cur] = newId;
            for (cur = pre[cur]; cur != i; cur = pre[cur]) id[cur] = newId;
            //bump the newId for the next available new Id
            newId++;
        }
        //If there is no loop, newId will keep 0
        if (newId == 0) return newId;

        for (int i = 0; i < n; i++) {
            if (marked[i] == -1) id[i] = newId++;
        }

        return newId;
    }

    private void reconstructGraph(int[] id, double[] minCost, int newN) {
        //for each edge, subtract incoming path weight with minCost of nodes
        //replace edge id with newly assigned ids
        //adjust # of nodes and root's new id
        //The reason we subtract the weight when we contract loop is:
        //We need to kick out one path from the loop but the current loop would be minimum cost to connect the nodes in loop
        //If we want to replace one of them from the loop, we want to choose some other paths have lowest difference from the minimum incoming weight
        //This operation makes sure when we choose path to the loop, we will choose lowest cost addition
        for (Edge e : edges) {
            e.weight -= minCost[e.toId];
            e.toId = id[e.toId];
            e.fromId = id[e.fromId];
        }
        n = newN;
        rootId = id[rootId];
    }

}
