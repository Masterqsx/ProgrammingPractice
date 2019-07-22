class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((l, r) -> r - l);
        for (int stone : stones) pq.add(stone);
        while (pq.size() > 1) {
            int s1 = pq.poll();
            int s2 = pq.poll();
            if (s1 != s2) pq.add(Math.abs(s1 - s2));
        }
        if (pq.size() > 0) return pq.peek();
        else return 0;
    }
}
