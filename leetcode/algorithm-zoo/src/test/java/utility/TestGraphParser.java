package utility;

import org.junit.Test;

import java.io.IOException;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class TestGraphParser {
    private static final String TINY_EWD = "src/test/resources/tinyEWD.txt";

    @Test
    public void testParse() throws IOException {
        Map<String, Map<String, Double>> graph = GraphParser.parse(TINY_EWD);
        assertEquals(8, graph.size());
    }
}
