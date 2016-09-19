class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        int d = gcd(x, y);
        return d == 0 || z % d == 0;
    }
    int gcd(int x, int y){
        if (x == 0) return y;
        if (y == 0) return x;
        if (x % 2 == 0 && y % 2 == 0) return 2 * gcd(x/2, y/2);
        if (x % 2 == 0) return gcd(x/2, y);
        if (y % 2 == 0) return gcd(x, y/2);
        return gcd(abs(x-y), min(x, y));
    }
};