package algorithm.graph;

import org.junit.Test;
import utility.GraphParser;

import java.io.IOException;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;


public class TestMyChuLiu {
    private static final String TINY_EWD = "src/test/resources/tinyEWD.txt";

    @Test
    public void testGetResult() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parse(TINY_EWD);
        MyChuLiu mst = new MyChuLiu(graph, "7");
        mst.getResult();
        assertTrue(Math.abs(mst.minMstWeight - 2.6) < 0.001);
        assertEquals("5", mst.prePath.get("4"));
        assertEquals("5", mst.prePath.get("1"));
        assertEquals("7", mst.prePath.get("7"));
        assertEquals("1", mst.prePath.get("3"));
        assertEquals("3", mst.prePath.get("6"));
        assertEquals("0", mst.prePath.get("2"));
        assertEquals("6", mst.prePath.get("0"));
    }
}
