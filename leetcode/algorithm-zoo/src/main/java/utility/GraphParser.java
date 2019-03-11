package utility;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class GraphParser {
    public static Map<String, Map<String, Double>> parse(String path) throws IOException {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));

        String curLine;
        while ((curLine = reader.readLine()) != null) {
            String[] values = curLine.split(" ");
            if (values.length == 3) {
                if (!graph.containsKey(values[0])) graph.put(values[0], new HashMap<>());
                graph.get(values[0]).put(values[1], Double.valueOf(values[2]));
            }
        }

        return graph;
    }
}
