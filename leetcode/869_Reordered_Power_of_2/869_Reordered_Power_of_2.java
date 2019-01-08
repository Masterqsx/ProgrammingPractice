class Solution {
    public boolean bp(LinkedList<Integer> candidate, int number) {
        if (candidate.size() <= 0) {
            return (number & (number - 1)) == 0;
        }
        for (int i = 0; i < candidate.size(); i++) {
            int cur = candidate.get(i);
            if (number == 0 && cur == 0) continue;
            candidate.remove(i);
            if (bp(candidate, number * 10 + cur)) return true;
            candidate.add(i, cur);
        }
        return false;
    } 
    public boolean reorderedPowerOf2(int N) {
        LinkedList<Integer> candidate = new LinkedList<>();
        while(N > 0) {
            candidate.add(N % 10);
            N /= 10;
        }
        return bp(candidate, 0);
    }
}
