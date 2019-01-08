class Solution {
    public int numFriendRequests(int[] ages) {
        Map<Integer, Integer> counts = new HashMap<>();
        int res = 0;
        for (int age : ages) {
            counts.put(age, counts.getOrDefault(age, 0) + 1);
        } 
        for (Map.Entry<Integer, Integer> e1 : counts.entrySet()) {
            if (e1.getKey() > 14) res += e1.getValue() * (e1.getValue() - 1);
            for (Map.Entry<Integer, Integer> e2 : counts.entrySet()) {
                if (e1.getKey() == e2.getKey()) continue;
                if (e2.getKey() > e1.getKey() * 0.5 + 7
                   && e2.getKey() <= e1.getKey()
                   && (e2.getKey() <= 100 || e1.getKey() >= 100)) {
                    res += e1.getValue() * e2.getValue();
                }
            }
        }
        return res;
    }
}
