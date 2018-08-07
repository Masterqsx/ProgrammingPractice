class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        char[] res = new char[S.length()];
        long shift = 0;
        for (int i = shifts.length - 1; i >= 0; i--) {
            shift += shifts[i];
            long tmp = shift % 26;
            if (tmp > ('z' - S.charAt(i))) {
                tmp -= 'z' - S.charAt(i) + 1;
                res[i] = (char)('a' + tmp);
            } else res[i] = (char)(S.charAt(i) + tmp);
        }
        return new String(res);
    }
}
