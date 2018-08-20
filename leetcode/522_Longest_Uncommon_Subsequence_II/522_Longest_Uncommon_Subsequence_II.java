class Solution {
    public int findLUSlength(String[] strs) {
        Map<String, Integer> freq = new HashMap<>();
        for (String str : strs) {
            if (freq.containsKey(str)) freq.put(str, freq.get(str) + 1);
            else freq.put(str, 1);
        }
        List<Map.Entry<String, Integer>> sortedFreq = new ArrayList<>(freq.entrySet());
        Collections.sort(sortedFreq, (Map.Entry<String, Integer> l, Map.Entry<String, Integer> r) -> r.getKey().length() - l.getKey().length());
        for (int i = 0; i < sortedFreq.size(); i++) {
            if (sortedFreq.get(i).getValue() == 1) {
                boolean flag = true;
                for (int j = 0; j < i; j++) {
                    flag = flag && valid(sortedFreq.get(i).getKey(), sortedFreq.get(j).getKey());
                    if (!flag) break;
                }
                if (flag) return sortedFreq.get(i).getKey().length();
            }
        }
        return -1;
    }
    
    public boolean valid(String sub, String str) {
        if (sub.length() >= str.length()) return true;
        int index = 0;
        for (int i = 0; i < str.length() && index < sub.length(); i++) {
            if (str.charAt(i) == sub.charAt(index)) index++;
        }
        return index != sub.length();
    }
}
