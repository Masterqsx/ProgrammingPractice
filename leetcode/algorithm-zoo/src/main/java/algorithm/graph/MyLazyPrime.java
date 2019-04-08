package algorithm.graph;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class MyLazyPrime {
    public static class Edge {
        public String from;
        public String to;
        public double weight;
        public Edge(String from, String to, double weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    private static PriorityQueue<Edge> pq;
    private static Set<String> marked;

    public static List<Edge> getMST(Map<String, Map<String, Double>> graph) {
        pq = new PriorityQueue<Edge>((l, r) -> {
            if (l.weight < r.weight) return -1;
            else if (l.weight > r.weight) return 1;
            else return 0;
        });
        marked = new HashSet<>();
        List<Edge> mst = new ArrayList<>();
        for (Map.Entry<String, Map<String, Double>> entryI : graph.entrySet()) {
            if (marked.contains(entryI.getKey())) continue;
            marked.add(entryI.getKey());
            for (Map.Entry<String, Double> entryJ : entryI.getValue().entrySet()) {
                pq.add(new Edge(entryI.getKey(), entryJ.getKey(), entryJ.getValue()));
            }
            expand(graph, mst);
        }
        return mst;
    }

    public static void expand(Map<String, Map<String, Double>> graph, List<Edge> mst) {
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (marked.contains(cur.from) && marked.contains(cur.to)) continue;
            String newNode = marked.contains(cur.from) ? cur.to : cur.from;
            mst.add(cur);
            marked.add(newNode);
            if (graph.containsKey(newNode)) {
                for (Map.Entry<String, Double> entry : graph.get(newNode).entrySet()) {
                    pq.add(new Edge(newNode, entry.getKey(), entry.getValue()));
                }
            }
        }
    }
}
