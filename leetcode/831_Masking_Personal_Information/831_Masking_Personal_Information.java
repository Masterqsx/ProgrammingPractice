class Solution {
    public String maskPII(String S) {
        StringBuffer res = new StringBuffer();
        if (S.indexOf('@') != -1) {
            S = S.toLowerCase();
            res.append(S.charAt(0));
            res.append("*****");
            res.append(S.substring(S.indexOf('@') - 1));
        } else {
            S = S.replaceAll("\\D", "");
            if (S.length() > 10) {
                res.append('+');
                res.append(String.join("", Collections.nCopies(S.length() - 10, "*")));
                res.append('-');
            }
            res.append("***-***-");
            res.append(S.substring(S.length() - 4));
        }
        
        return res.toString();
    }
}
