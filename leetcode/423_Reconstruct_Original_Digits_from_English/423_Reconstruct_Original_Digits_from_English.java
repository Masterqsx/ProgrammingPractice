class Solution {
    public String originalDigits(String s) {
        int[] count = new int[10];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'z') count[0]++;
            if (s.charAt(i) == 'w') count[2]++;
            if (s.charAt(i) == 'u') count[4]++;
            if (s.charAt(i) == 'x') count[6]++;
            if (s.charAt(i) == 'g') count[8]++;
            if (s.charAt(i) == 'f') count[5]++;// 5 - 4 
            if (s.charAt(i) == 's') count[7]++;// 7 - 6
            if (s.charAt(i) == 'i') count[9]++;// 9 - 6 - 8 - 5
            if (s.charAt(i) == 'h') count[3]++;// 3 - 8
            if (s.charAt(i) == 'o') count[1]++;// 1 - 4 - 0 - 2
        }
        count[5] -= count[4];
        count[7] -= count[6];
        count[9] -= count[6] + count[5] + count[8];
        count[3] -= count[8];
        count[1] -= count[0] + count[2] + count[4];
        StringBuilder ss = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            while (count[i] > 0) {
                ss.append(new Integer(i).toString());
                count[i]--;
            }
        }
        return ss.toString();
    }
}
