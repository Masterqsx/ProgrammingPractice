class Solution {
    private boolean match(String s, String p) {
        int i = 2, j = 2;
        s = "^^" + s + "$";
        p = "^^" + p + "$";
        while (i < s.length() && j < p.length()) {
            if (s.charAt(i) == p.charAt(j)) {
                i++;
                j++;
            } else if (s.charAt(i - 2) == s.charAt(i - 1) && s.charAt(i - 1) == s.charAt(i) || s.charAt(i - 1) == s.charAt(i) && s.charAt(i) == s.charAt(i + 1)) i++;
            else return false;
        }
        return true;
    }
    public int expressiveWords(String S, String[] words) {
        int res = 0;
        for (String word : words) {
            if (match(S, word)) res++;
        }
        return res;
    }
}
