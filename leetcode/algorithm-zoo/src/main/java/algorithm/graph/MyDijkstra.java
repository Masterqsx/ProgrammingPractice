package algorithm.graph;

import algorithm.priority_queue.MyIndexPriorityQueue;

import java.util.HashMap;
import java.util.Map;

public class MyDijkstra {
    //My graph definition is Map<String, Map<String, Double>>
    //The requirement is to find the shortest paths from the single source and their path in graph
    private Map<String, Map<String, Double>> graph;
    private Map<String, Double> dis;
    private Map<String, String> path;
    private MyIndexPriorityQueue<String, Double> pq;

    public MyDijkstra(Map<String, Map<String, Double>> graph) {
        this.graph = graph;
    }

    public void searchSP(String source) {
        dis = new HashMap<>();
        path = new HashMap<>();
        pq = new MyIndexPriorityQueue<>((l, r) -> {
            if (l < r) return -1;
            if (l > r) return 1;
            else return 0;
        });

        if (!graph.containsKey(source)) return;

        initialize(source);

        while (!isEmpty()) {
            Map.Entry<String, Double> curVertex = pop();
            relax(curVertex);
        }
    }

    public Map<String, Double> getDis() {
        return dis;
    }

    public Map<String, String> getPath() {
        return path;
    }

    private void initialize(String source) {
        dis.put(source, 0.0);
        for (Map.Entry<String, Double> entry : graph.get(source).entrySet()) {
            push(entry.getKey(), entry.getValue());
            path.put(entry.getKey(), source);
        }
    }

    private void relax(Map.Entry<String, Double> curVertex) {
        dis.put(curVertex.getKey(), curVertex.getValue());
        for (Map.Entry<String, Double> entry : graph.get(curVertex.getKey()).entrySet()) {

            if (dis.containsKey(entry.getKey())) continue;

            if (update(entry.getKey(), curVertex.getValue() + entry.getValue())) {
                path.put(entry.getKey(), curVertex.getKey());
            }
        }
    }

    private void push(String vertex, double weight) {
        pq.insert(vertex, weight);
    }

    private Map.Entry<String, Double> pop() {
        Map.Entry<String, Double> res = pq.top();
        pq.delTop();
        return res;
    }

    private boolean isEmpty() {
        return pq.size() == 0;
    }

    private boolean update(String vertex, double weight) {
        if (pq.containsKey(vertex)) {
            double curWeight = pq.get(vertex);
            if (weight < curWeight) {
                pq.update(vertex, weight);
                return true;
            } else return false;
        } else {
            pq.insert(vertex, weight);
            return true;
        }
    }
}
