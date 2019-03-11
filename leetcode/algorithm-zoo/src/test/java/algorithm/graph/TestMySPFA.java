package algorithm.graph;

import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.Map;

import static org.junit.Assert.assertTrue;

public class TestMySPFA {
    @Test
    public void testSearchSP() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parse("src/test/resources/tinyEWD.txt");

        MySPFA spfa = new MySPFA(graph);
        spfa.searchSP("0");
        Map<String, Double> dis = spfa.getDis();
        assertTrue(Math.abs(dis.get("0") - 0.0) < 0.0001);
        assertTrue(Math.abs(dis.get("1") - 1.05) < 0.0001);
        assertTrue(Math.abs(dis.get("2") - 0.26) < 0.0001);
        assertTrue(Math.abs(dis.get("3") - 0.99) < 0.0001);
        assertTrue(Math.abs(dis.get("4") - 0.38) < 0.0001);
        assertTrue(Math.abs(dis.get("5") - 0.73) < 0.0001);
        assertTrue(Math.abs(dis.get("6") - 1.51) < 0.0001);
        assertTrue(Math.abs(dis.get("7") - 0.60) < 0.0001);
    }
}
