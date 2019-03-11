package algorithm.graph;

import org.junit.Before;
import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class TestMyDijkstra {
    private Map<String, Map<String, Double>> graph;

    @Before
    public void setUp() {
        graph = new HashMap<String, Map<String, Double>>(){{
            put("4", new HashMap<String, Double>(){{
                put("5", 0.35);
                put("7", 0.37);
            }});
            put("5", new HashMap<String, Double>(){{
                put("4", 0.35);
                put("7", 0.28);
                put("1", 0.32);
            }});
            put("7", new HashMap<String, Double>(){{
                put("5", 0.28);
                put("3", 0.39);
            }});
            put("0", new HashMap<String, Double>(){{
                put("4", 0.38);
                put("2", 0.26);
            }});
            put("1", new HashMap<String, Double>(){{
                put("3", 0.29);
            }});
            put("2", new HashMap<String, Double>(){{
                put("7", 0.34);
            }});
            put("6", new HashMap<String, Double>(){{
                put("2", 0.40);
                put("0", 0.58);
                put("4", 0.93);
            }});
            put("3", new HashMap<String, Double>(){{
                put("6", 0.52);
            }});
        }};
    }

    @Test
    public void testSearchSP() {
        MyDijkstra dijkstra = new MyDijkstra(graph);
        dijkstra.searchSP("0");
        Map<String, Double> dis = dijkstra.getDis();
        Map<String, String> path = dijkstra.getPath();

        assertTrue(Math.abs(dis.get("0") - 0.0) < 0.0001);
        assertTrue(Math.abs(dis.get("1") - 1.05) < 0.0001);
        assertTrue(Math.abs(dis.get("2") - 0.26) < 0.0001);
        assertTrue(Math.abs(dis.get("3") - 0.99) < 0.0001);
        assertTrue(Math.abs(dis.get("4") - 0.38) < 0.0001);
        assertTrue(Math.abs(dis.get("5") - 0.73) < 0.0001);
        assertTrue(Math.abs(dis.get("6") - 1.51) < 0.0001);
        assertTrue(Math.abs(dis.get("7") - 0.60) < 0.0001);

        assertEquals("5", path.get("1"));
        assertEquals("0", path.get("2"));
        assertEquals("7", path.get("3"));
        assertEquals("0", path.get("4"));
        assertEquals("4", path.get("5"));
        assertEquals("3", path.get("6"));
        assertEquals("2", path.get("7"));
    }
}
