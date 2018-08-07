class Solution {
    private boolean validate(String l, String r) {
        if (l.charAt(0) == '0' && l.length() > 1) return false;
        if (r!= null && r.length() > 0 && r.charAt(r.length() - 1) == '0') return false;
        return true;
    }
    
    private void backTracking(List<String> strList, List<String> res, String tempStr, int index) {
        if (index == 2) {
            res.add(tempStr);
            return;
        }
        String str = strList.get(index);
        for (int i = 1; i <= str.length(); i++) {
            if (validate(str.substring(0, i), str.substring(i))) {
                String temp = tempStr;
                temp += str.substring(0, i) + (i == str.length() ? "" : ".") + str.substring(i);
                if (index == 0) temp = "(" + temp + ", ";
                else temp += ")";
                backTracking(strList, res, temp, index + 1);
            }
        }
    }
    
    public List<String> ambiguousCoordinates(String S) {
        S = S.substring(1, S.length() - 1);
        List<String> res = new ArrayList<String>();
        for (int i = 1; i < S.length(); i++) {
            String l = S.substring(0, i);
            String r = S.substring(i);
            backTracking(Arrays.asList(l, r), res, new String(), 0);
        }
        return res;
    }
}
