package algorithm.graph;

import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

import static org.junit.Assert.assertTrue;

public class TestMyTopologicalSortDFS {
    private static final String TINY_DAG = "src/test/resources/tinyDAG.txt";

    @Test
    public void testSort() throws IOException {
        Map<String, Map<String, Double>> dag = GraphParser.parse(TINY_DAG);
        MyTopologicalSortDFS dfs = new MyTopologicalSortDFS();
        Stack<String> order = dfs.sort(dag);

        Map<String, Integer> precedence = new HashMap<>();
        int index = 0;
        while (!order.empty()) precedence.put(order.pop(), index++);

        for (Map.Entry<String, Map<String, Double>> entry : dag.entrySet()) {
            for (Map.Entry<String, Double> edge : dag.get(entry.getKey()).entrySet()) {
                assertTrue(precedence.get(entry.getKey()) < precedence.get(edge.getKey()));
            }
        }

    }
}
