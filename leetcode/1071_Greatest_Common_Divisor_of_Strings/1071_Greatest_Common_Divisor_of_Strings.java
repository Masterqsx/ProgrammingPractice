class Solution {
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    private boolean isValid(String str, int len) {
        if (str.length() % len != 0) return false;
        for (int j = 0; j < len; j++) {
            for (int i = 1; i < str.length() / len; i++) {
                if (str.charAt(i * len + j) != str.charAt((i - 1) * len + j)) return false;
            }
        }
        return true;
    }
    public String gcdOfStrings(String str1, String str2) {
        int len = gcd(str1.length(), str2.length());
        if (isValid(str1, len) && isValid(str2, len) && str1.substring(0, len).equals(str2.substring(0, len))) return str1.substring(0, len);
        else return "";
    }
}
