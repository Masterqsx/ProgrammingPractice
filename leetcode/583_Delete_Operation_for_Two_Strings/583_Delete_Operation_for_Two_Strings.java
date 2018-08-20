class Solution {
    public int minDistance(String word1, String word2) {
        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
        for (int i = 0; i <= word1.length(); i++) {
            dp.add(new ArrayList<Integer>());
            for (int j = 0; j <= word2.length(); j++) {
                if (i == 0) dp.get(i).add(j);
                else if (j == 0) dp.get(i).add(i);
                else dp.get(i).add(0);
            }
        }
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                int res = Integer.min(dp.get(i - 1).get(j - 1) + (word1.charAt(i - 1) == word2.charAt(j - 1)?0:2), 
                            Integer.min(dp.get(i - 1).get(j) + 1, dp.get(i).get(j - 1) + 1));
                dp.get(i).set(j, res);
            }
        }
        return dp.get(word1.length()).get(word2.length());
    }
}
