package algorithm.graph;

import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class TestMyDirectedCycle {
    private static final String TINY_DAG = "src/test/resources/tinyDAG.txt";
    private static final String TINY_EWD = "src/test/resources/tinyEWD.txt";
    private static final String MEDIUM_EWD = "src/test/resources/mediumEWD.txt";

    @Test
    public void testHasCycle() throws IOException {
        Map<String, Map<String, Double>> dag = GraphParser.parse(TINY_DAG);
        Map<String, Map<String, Double>> ewd = GraphParser.parse(TINY_EWD);
        Map<String, Map<String, Double>> medium = GraphParser.parse(MEDIUM_EWD);

        assertEquals(false, MyDirectedCycle.hasCycle(dag));
        assertEquals(true, MyDirectedCycle.hasCycle(ewd));
        assertEquals(true, MyDirectedCycle.hasCycle(medium));
    }
}
