package algorithm.graph;

import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class MyTopologicalSortDFS {
    private Stack<String> order;
    private Set<String> visiting;
    private Set<String> visited;
    private boolean hasCycle = false;

    public Stack<String> sort(Map<String, Map<String, Double>> graph) {
        order = new Stack<>();
        visiting = new HashSet<>();
        visited = new HashSet<>();

        for (Map.Entry<String, Map<String, Double>> entry : graph.entrySet()) {
            if (!hasCycle && !visited.contains(entry.getKey())) dfs(graph, entry.getKey());
        }

        return order;
    }

    private void dfs(Map<String, Map<String, Double>> graph, String v) {
        visiting.add(v);
        if (graph.containsKey(v)) {
            for (Map.Entry<String, Double> entry : graph.get(v).entrySet()) {
                if (visiting.contains(entry.getKey())) hasCycle = true;
                if (visited.contains(entry.getKey())) continue;

                if (hasCycle) return;
                dfs(graph, entry.getKey());
            }
        }

        visiting.remove(v);
        visited.add(v);
        order.push(v);
    }

}
