class Solution {
    public class Index {
        public int x;
        public char c;
        public Integer h;
        public Index(int x, char c, Integer h) {
            this.x = x;
            this.c = c;
            this.h = h;
        }
    }
    public List<int[]> getSkyline(int[][] buildings) {
        List<Index> indices = new ArrayList<>();
        for (int i = 0; i < buildings.length; i++) {
            Integer height = new Integer(buildings[i][2]);
            indices.add(new Index(buildings[i][0], 's', height));
            indices.add(new Index(buildings[i][1], 'e', height));
        }
        Collections.sort(indices, (l, r) -> {
            if (l.x != r.x) return l.x - r.x;
            else if (l.c != r.c) return r.c - l.c;
            else if (l.c == 's') return r.h - l.h;
            else return l.h - r.h;
            });
        PriorityQueue<Integer> pq = new PriorityQueue<>((l, r) -> r - l);
        pq.add(new Integer(0));
        List<int[]> res = new ArrayList<>();
        int top = 0;
        for (Index index : indices) {
            if (index.c == 's') pq.add(index.h);
            else pq.remove(index.h);
            if (pq.peek() != top) {
                top = pq.peek().intValue();
                int[] temp = {index.x, top};
                res.add(temp);
            }
        }
        return res;
    }
}
