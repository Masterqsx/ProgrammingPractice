class Solution {
    int gcd(int p, int q) {
        if (q == 0) return p;
        return gcd(q, p % q);
    }
    public int mirrorReflection(int p, int q) {
        int lcm = p * q / gcd(p, q);
        int x = lcm / p, y = lcm / q;
        if (y % 2 == 0) return 2;
        else if (x % 2 == 0) return 0;
        else return 1;
    }
}
