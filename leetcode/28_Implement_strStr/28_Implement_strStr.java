class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;
        int[] lps = mismatch(needle);
        int i = 0, j = 0;
        for (; i < haystack.length(); i++) {
            if (j == needle.length()) return i - j;
            while (j != 0 && haystack.charAt(i) != needle.charAt(j)) j = lps[j - 1];
            if (haystack.charAt(i) == needle.charAt(j)) j++;
        }
        if (j == needle.length()) return i - j;
        return -1;
    }
    
    public int[] mismatch(String needle) {
        int[] lps = new int[needle.length()];
        for (int i = 1, j = 0; i < needle.length(); i++) {
            while (j != 0 && needle.charAt(i) != needle.charAt(j)) j = lps[j - 1];
            if (needle.charAt(i) == needle.charAt(j)) lps[i] = ++j;
        }
        return lps;
    }
}
