package algorithm.graph;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class MyHungarian {
    public static Map<String, String> findMaxMatch(Map<String, Set<String>> Edges) {
        Map<String, String> match = new HashMap<>();
        for (String u : Edges.keySet()) {
            //Start from a unmatched point to find the augmenting path
            //The visited has to be clear after search since it represent the visited during one dfs
            //One successful dfs will fix a unmatched point in u group
            //Check if match result contains u is actually necessary since each dfs only match current u
            //The recursive call inside dfs only make solved node u have a new match
            //If one node return false which means this node will not have match which is not a perfect match
            if (!match.containsKey(u)) dfs(u, match, Edges, new HashSet<String>());
        }
        return match;
    }

    private static boolean dfs(String u, Map<String, String> match, Map<String, Set<String>> Edges, Set<String> visited) {
        for (String v : Edges.get(u)) {
            //visited represent the points visited during this search, avoid duplicated match (two u points match to the same v)
            //visited only store points in v group
            if (!visited.contains(v)) {
                visited.add(v);
                //Trying to find a unmatched v
                if (!match.containsKey(v) || dfs(match.get(v), match, Edges, visited)) {
                    //During search, if we going to the next level, the v will find another match
                    //Which leaves match.get(match.get(v)) != v
                    //During the deeper level search of augmenting path
                    // , we will shift to the newly find unmatched point in v one by one
                    // and leave this v to the u
                    match.put(v, u);
                    match.put(u, v);
                    return true;
                }
            }
        }
        return false;
    }
}
