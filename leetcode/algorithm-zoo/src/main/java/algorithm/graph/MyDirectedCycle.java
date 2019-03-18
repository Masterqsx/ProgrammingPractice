package algorithm.graph;

import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class MyDirectedCycle {
    public static boolean hasCycle(Map<String, Map<String, Double>> graph) {
        Set<String> visiting = new HashSet<>();
        Set<String> visited = new HashSet<>();

        boolean res = false;
        for (Map.Entry<String, Map<String, Double>> entry : graph.entrySet()) {
            if (!visited.contains(entry.getKey())) res = res | dfs(graph, visiting, visited, entry.getKey());
        }
        return res;
    }

    private static boolean dfs(Map<String, Map<String, Double>> graph, Set<String> visting, Set<String> visited, String v) {
        visting.add(v);
        if (graph.containsKey(v)) {
            for (Map.Entry<String, Double> entry : graph.get(v).entrySet()) {
                if (visting.contains(entry.getKey())) return true;
                if (visited.contains(entry.getKey())) continue;

                if (dfs(graph, visting, visited, entry.getKey())) return true;
            }
        }
        visting.remove(v);
        visited.add(v);

        return false;
    }
}
