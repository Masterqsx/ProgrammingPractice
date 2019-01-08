class Solution {
    public int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        n = Math.min(n, 3);
        if (m == 1) {
            return n + 1;
        }
        else if (m == 2) {
            if (n == 1) return 2;
            else if (n == 2) return 4;
            else return 7;
        }
        else {
            return (int)Math.pow(2, n);
        }
    }
}
