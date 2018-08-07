class Solution {
    public String reorganizeString(String S) {
        int[] charCount = new int[26];
        boolean[] maxChar = new boolean[26];
        int maxCount = 0;
        for (int i = 0; i < S.length(); i++) {
            charCount[S.charAt(i) - 'a']++;
            if (charCount[S.charAt(i) - 'a'] >= maxCount) {
                if (charCount[S.charAt(i) - 'a'] > maxCount) maxChar = new boolean[26];
                maxChar[S.charAt(i) - 'a'] = true;
                maxCount = charCount[S.charAt(i) - 'a'];
            }
        }
        if (2 * maxCount - 1 > S.length()) return new String();
        
        char[] res = new char[S.length()];
        int index = 0;
        for (int i = 0; i < 26; i++) {
            if (maxChar[i]) {
                for (int j = 0; j < maxCount; j++) {
                    if (index >= res.length) index = 1;
                    res[index] = (char)(i + 'a');
                    index += 2;
                }
                charCount[i] = 0;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (charCount[i] > 0) {
                if (index >= res.length) index = 1;
                res[index] = (char)(i + 'a');
                charCount[i]--;
                index += 2;
            }
        }
        
        return new String(res);
    }
}
