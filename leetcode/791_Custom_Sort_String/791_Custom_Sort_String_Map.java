class Solution {
    private class Pair {
        public char c = '\0';
        public int rank = -1;
        public int n = 0;
        public Pair(char c, int rank, int n) {
            this.c = c;
            this.rank = rank;
            this.n = n;
        }
    }
    public String customSortString(String S, String T) {
        Map<Integer, Pair> m1 = new HashMap<>();
        Map<Character, Pair> m2 = new HashMap<>();
        Map<Character, Integer> unsorted = new HashMap<>();
        
        StringBuffer res = new StringBuffer();
        
        for (int i = 0; i < S.length(); i++) {
            m1.put(i, new Pair(S.charAt(i), i, 0));
            m2.put(S.charAt(i), m1.get(i));
        }
        
        for (int i = 0; i < T.length(); i++) {
            if (m2.containsKey(T.charAt(i))) m2.get(T.charAt(i)).n += 1;
            else if (unsorted.containsKey(T.charAt(i))) unsorted.put(T.charAt(i), unsorted.get(T.charAt(i)) + 1);
            else unsorted.put(T.charAt(i), 1);
        }
        
        for (int i = 0; i < S.length(); i++) {
            for (int j = 0; j < m1.get(i).n; j++) res.append(m1.get(i).c);
        }
        
        for (Map.Entry<Character, Integer> e : unsorted.entrySet()) {
            for (Integer j = 0; j < e.getValue(); j++) res.append(e.getKey());
        }
        
        return res.toString();
    }
}
