class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        int d = gcd(x, y);
        return d == 0 || z % d == 0;
    }
    int gcd(int x, int y){
        return y == 0?x:gcd(y, x%y);
    }
};