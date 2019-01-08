class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        Map<Character, List<Integer>> bucket = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            if (!bucket.containsKey(pattern.charAt(i))) bucket.put(pattern.charAt(i), new ArrayList<Integer>());
            bucket.get(pattern.charAt(i)).add(i);
        }
        List<String> res = new ArrayList<>();
        Set<Character> dump = new HashSet();
        for (int i = 0; i < words.length; i++) {
            dump.clear();
            boolean flag = true;
            String word = words[i];
            
            for (Map.Entry<Character, List<Integer>> entry : bucket.entrySet()) {
                if (!flag) break;
                if (dump.contains(word.charAt(entry.getValue().get(0)))) {
                    flag = false;
                    break;
                }
                if (entry.getValue().size() > 1) {
                    for (int j = 1; j < entry.getValue().size() && flag; j++) {
                        if (word.charAt(entry.getValue().get(j)) != word.charAt(entry.getValue().get(j - 1)))
                            flag = false;
                    }
                }
                if (flag) dump.add(word.charAt(entry.getValue().get(0)));
            }
            if (flag) res.add(word);
        }
        return res;
    }
}
