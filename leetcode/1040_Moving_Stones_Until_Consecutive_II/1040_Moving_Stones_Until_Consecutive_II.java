class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int mi = Integer.MAX_VALUE;
        int sz = stones.length;
        Deque<Integer> q = new LinkedList<>();
        for (int i = 0; i < stones.length; i++) {
            if (q.size() == 0 || q.peekFirst() + sz > stones[i]) q.addLast(stones[i]);
            else if (q.peekFirst() + sz <= stones[i]) {
                if (sz - q.size() == 1 && q.peekLast() - q.peekFirst() == sz - 2) mi = Math.min(mi, sz - q.size() + 1);
                else mi = Math.min(mi, sz - q.size());
                while (q.size() > 0 && q.peekFirst() + sz <= stones[i]) q.pollFirst();
                q.addLast(stones[i]);
            }
        }
        if (sz - q.size() == 1 && q.peekLast() - q.peekFirst() == sz - 2) mi = Math.min(mi, sz - q.size() + 1);
        else mi = Math.min(mi, sz - q.size());
        
        return new int[]{mi, Math.max(stones[stones.length - 1] - stones[1], stones[stones.length - 2] - stones[0]) - stones.length + 2};
    }
}
