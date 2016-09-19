class Solution {
public:
    int trailingZeroes(int n) {
        long res = 0, step = 5;
        while (n >= step){
            res += n / step;
            step *= 5;
        }
        return res;
    }
};