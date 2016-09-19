class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        long res = 0, step = 1, pre = 0;
        while (n > 0){
            if (res > 2147483647) return INT_MAX;
            int cur = n % 10;
            res += n / 10 * step;
            if (cur > 1) res += step;
            else if (cur == 1) res += (pre + 1);
            pre += cur * step;
            step *= 10;
            n /= 10;
        }
        return res;
    }
};