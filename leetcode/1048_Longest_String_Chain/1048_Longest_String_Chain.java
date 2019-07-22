class Solution {
    private boolean isPred(String w1, String w2) {
        if (Math.abs(w1.length() - w2.length()) != 1) return false;
        int[] alph1 = new int[26];
        int[] alph2 = new int[26];
        for (int i = 0; i < w1.length(); i++) alph1[w1.charAt(i) - 'a']++;
        for (int i = 0; i < w2.length(); i++) alph2[w2.charAt(i) - 'a']++;
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            diff += Math.abs(alph1[i] - alph2[i]);
        }
        return diff == 1;
    }
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (l, r) -> l.length() - r.length());
        int[] dp = new int[words.length];
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < words.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (isPred(words[i], words[j])) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
