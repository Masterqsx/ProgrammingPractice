package algorithm.graph;

import org.junit.Assert;
import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.List;
import java.util.Map;

public class TestMyLazyPrime {
    private static final String TINY_EWG = "src/test/resources/tinyEWG.txt";
    private static final String MEDIUM_EWG = "src/test/resources/mediumEWG.txt";

    @Test
    public void testGetMSTWithTiny() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parseUndirected(TINY_EWG);
        List<MyLazyPrime.Edge> mst = MyLazyPrime.getMST(graph);
        double weight = 0.0;
        for (MyLazyPrime.Edge e : mst) weight += e.weight;
        Assert.assertTrue(Math.abs(1.81 - weight) < 0.00001);
    }

    @Test
    public void testGetMSTWithMedium() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parseUndirected(MEDIUM_EWG);
        List<MyLazyPrime.Edge> mst = MyLazyPrime.getMST(graph);
        double weight = 0.0;
        for (MyLazyPrime.Edge e : mst) weight += e.weight;
        Assert.assertTrue(Math.abs(10.46351 - weight) < 0.001);
    }

}
