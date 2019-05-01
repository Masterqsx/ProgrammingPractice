class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] res = new int[2];
        int n0 = Math.min(Math.min(a, b), c);
        int n2 = Math.max(Math.max(a, b), c);
        int n1 = a ^ b ^ c ^ n0 ^ n2;
        if (n1 - n0 > 2 && n2 - n1 > 2) res[0] = 2;
        else if (n1 - n0 == 1 && n2 - n1 == 1) res[0] = 0;
        else res[0] = 1;
        res[1] = n2 - n0 - 2;
        return res;
    }
}
