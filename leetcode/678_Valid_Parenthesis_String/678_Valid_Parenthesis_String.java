class Solution {
    public boolean checkValidString(String s) {
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                a++;
                b++;
            } else if (s.charAt(i) == ')') {
                a--;
                b--;
            } else {
                a--;
                b++;
            }
            a = Integer.max(a, 0);
            if (b < 0) return false;
        }
        return a == 0;
    }
}
