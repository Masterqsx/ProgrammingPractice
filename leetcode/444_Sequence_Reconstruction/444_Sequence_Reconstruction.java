class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (List<Integer> seq : seqs) {
            int j = 0, k = 0;
            while (j < seq.size() && k < org.length) {
                if (org[k] == seq.get(j)) {
                    j++;k++;
                } else k++;
            }
            if (j != seq.size()) return false;
            
            for (int i = 0; i < seq.size() - 1; i++) {
                if (!graph.containsKey(seq.get(i))) graph.put(seq.get(i), new HashSet<>());
                graph.get(seq.get(i)).add(seq.get(i + 1));
            }
            if (seq.size() == 1 && !graph.containsKey(seq.get(0))) graph.put(seq.get(0), new HashSet<>());
        }
        for (int i = 0; i < org.length - 1; i++) {
            if (!graph.containsKey(org[i])) return false;
            if (!graph.get(org[i]).contains(org[i + 1])) return false;
        }
        if (org.length == 1) return graph.containsKey(org[0]);
        return true;
    }
}
