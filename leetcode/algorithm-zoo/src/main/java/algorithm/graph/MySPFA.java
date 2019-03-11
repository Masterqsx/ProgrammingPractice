package algorithm.graph;

import java.util.AbstractMap;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class MySPFA {
    private Map<String, Map<String, Double>> graph;
    private Map<String, Double> dis;
    private LinkedList<Map.Entry<String, Double>> queue;
    private Map<String, Integer> negativeCheck;

    public MySPFA(Map<String, Map<String, Double>> graph) { this.graph = graph; }

    public boolean searchSP(String source) {
        if (!graph.containsKey(source)) return false;

        initialize(source);
        while (!queue.isEmpty()) {
            Map.Entry<String, Double> curNode = queue.pollFirst();

            negativeCheck.put(curNode.getKey(), negativeCheck.getOrDefault(curNode.getKey(), 0) + 1);
            if (negativeCheck.get(curNode.getKey()) >= graph.size()) return false;

            relax(curNode);
        }
        return true;
    }

    public Map<String, Double> getDis() {
        return dis;
    }

    private void initialize(String source) {
        queue = new LinkedList<>();
        negativeCheck = new HashMap<>();
        dis = new HashMap<>();

        dis.put(source, 0.0);
        queue.add(new AbstractMap.SimpleEntry<>(source, 0.0));
    }

    private void relax(Map.Entry<String, Double> node) {
        for (Map.Entry<String, Double> entry : graph.get(node.getKey()).entrySet()) {
            if (!dis.containsKey(entry.getKey()) || dis.get(entry.getKey()) > node.getValue() + entry.getValue()) {
                dis.put(entry.getKey(), node.getValue() + entry.getValue());
                queue.add(new AbstractMap.SimpleEntry<>(entry.getKey(), dis.get(entry.getKey())));
            }
        }
    }
}
