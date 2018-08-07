class Solution {
    private class triple {
        public int index;
        public String source;
        public String target;
        public triple(){};
        public triple(int index, String source, String target) {
            this.index = index;
            this.source = source;
            this.target = target;
        }
    }
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        List<triple> operations = new ArrayList<>();
        for (int i = 0; i < indexes.length; i++) {
            operations.add(new triple(indexes[i], sources[i], targets[i]));
        }
        operations.sort((triple l, triple r) -> {return l.index - r.index;});
        StringBuilder sb = new StringBuilder();
        int curIndex = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (curIndex != operations.get(i).index) {
                sb.append(S.substring(curIndex, operations.get(i).index));
                curIndex = operations.get(i).index;
            }
            if (operations.get(i).source.equals(
                S.substring(operations.get(i).index, operations.get(i).index + operations.get(i).source.length()))) {
                sb.append(operations.get(i).target);
                curIndex += operations.get(i).source.length();
            }
        }
        if (curIndex < S.length()) sb.append(S.substring(curIndex));
        return sb.toString();
    }
}
