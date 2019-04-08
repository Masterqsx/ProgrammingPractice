package utility;

import org.junit.Test;

import java.io.IOException;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class TestGraphParser {
    private static final String TINY_EWD = "src/test/resources/tinyEWD.txt";

    @Test
    public void testParse() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parse(TINY_EWD);
        assertEquals(8, graph.size());
    }

    @Test
    public void testParseUndirected() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parseUndirected(TINY_EWD);
        for (Map.Entry<String, Map<String, Double>> entryI : graph.entrySet()) {
            for (Map.Entry<String, Double> entryJ : graph.get(entryI.getKey()).entrySet()) {
                assertTrue(graph.containsKey(entryJ.getKey()));
                assertTrue(graph.get(entryJ.getKey()).containsKey(entryI.getKey()));
            }
        }
    }
}
