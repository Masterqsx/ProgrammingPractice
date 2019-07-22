class Solution {
    public String removeDuplicates(String S) {
        StringBuffer res = new StringBuffer();
        res.append(S.charAt(0));
        for (int i = 1; i < S.length(); i++) {
            if (res.length() > 0 && res.charAt(res.length() - 1) == S.charAt(i)) {
                res.deleteCharAt(res.length() - 1);
            } else res.append(S.charAt(i));
        }
        return res.toString();
    }
}
