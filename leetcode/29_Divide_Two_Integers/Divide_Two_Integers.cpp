class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0))?-1:1;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        long remain = abs((long)dividend), temp = abs((long)divisor);
        int count = 1, res = 0;
        while (remain >= temp){
            if ((temp<<2) > remain){
                res += count;
                remain -= temp;
                temp = abs((long)divisor);
                count = 1;
            }
            else{
                temp <<= 2;
                count <<= 2;
            }
        }
        return sign * res;
    }
};