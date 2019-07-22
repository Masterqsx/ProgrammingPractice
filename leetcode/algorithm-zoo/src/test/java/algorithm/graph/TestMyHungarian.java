package algorithm.graph;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class TestMyHungarian {
    private static final String TINY_BIPARTITE = "src/test/resources/tinyBipartite.txt";

    private Map<String, Map<String, Double>> graph;

    private Map<String, Set<String>> EdgesStartFromU;

    @Before
    public void setUp() throws IOException {
        graph = GraphParser.parse(TINY_BIPARTITE);
        EdgesStartFromU = new HashMap<>();
        for (String idx : graph.keySet()) {
            if (!EdgesStartFromU.containsKey(idx)) EdgesStartFromU.put(idx, new HashSet<>());
            for (String toIdx : graph.get(idx).keySet()) {
                EdgesStartFromU.get(idx).add(toIdx);
            }
        }
    }

    @Test
    public void testFindMaxMatch() {
        Map<String, String> match = MyHungarian.findMaxMatch(EdgesStartFromU);
        for (Map.Entry<String, String> entry : match.entrySet()) {
            Assert.assertTrue(EdgesStartFromU.containsKey(entry.getKey())
                && EdgesStartFromU.get(entry.getKey()).contains(entry.getValue())
                || EdgesStartFromU.containsKey(entry.getValue())
                && EdgesStartFromU.get(entry.getValue()).contains(entry.getKey()));
        }
    }
}
