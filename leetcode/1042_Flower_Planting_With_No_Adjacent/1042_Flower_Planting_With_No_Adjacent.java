class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int[] path : paths) {
            if (!graph.containsKey(path[0])) graph.put(path[0], new HashSet<>());
            if (!graph.containsKey(path[1])) graph.put(path[1], new HashSet<>());
            graph.get(path[0]).add(path[1]);
            graph.get(path[1]).add(path[0]);
        }
        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            int[] choices = new int[4];
            if (graph.containsKey(i + 1)) {
                for (Integer neighbour : graph.get(i + 1)) {
                    if (res[neighbour - 1] != 0) choices[res[neighbour - 1] - 1] = 1;
                }
            }
            for (int j = 0; j < 4; j++) {
                if (choices[j] == 0) {
                    res[i] = j + 1;
                    break;
                }   
            }
        }
        return res;
    }
}
