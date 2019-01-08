class Solution {
    public int findA(String n) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < n.length() && n.charAt(i) != '+'; i++) {
            sb.append(n.charAt(i));
        }
        return Integer.parseInt(sb.toString());
    }
    public int findB(String n) {
        return Integer.parseInt(n.substring(n.indexOf("+", 1) + 1, n.indexOf("i")));
    }
    public String complexNumberMultiply(String a, String b) {
        int a1 = findA(a);
        int a2 = findA(b);
        int b1 = findB(a);
        int b2 = findB(b);
        return (new Integer(a1 * a2 - b1 * b2).toString()) + "+" + (new Integer(a1 * b2 + a2 * b1).toString()) + "i";
    }
}
