class Solution {
    public int countSubstrings(String s) {
        List<List<Boolean>> dp = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            dp.add(new ArrayList<Boolean>());
            for (int j = 0; j < s.length(); j++) dp.get(i).add(false);
        }
        for (int i = 0; i < s.length(); i++) dp.get(i).set(i, true);
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp.get(i).set(i + 1, true);
                dp.get(i + 1).set(i, true);
            }
        }
        for (int l = 3; l <= s.length(); l++) {
            for (int i = 0; i < s.length() - l + 1; i++) {
                dp.get(i).set(i + l - 1, dp.get(i + 1).get(i + l - 2) && (s.charAt(i) == s.charAt(i + l - 1)));
                dp.get(i + l - 1).set(i, dp.get(i).get(i + l - 1));
            }
        }
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (dp.get(i).get(j)) res++;
            }
        }
        return res;
    }
}
