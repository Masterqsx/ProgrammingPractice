class Solution {
public:
    int nextGreaterElement(int n) {
        int lastDigit = 0;
        long res = n;
        int digitCount[10];
        memset(digitCount, 0, 10 * sizeof(lastDigit));
        while (res > 0) {
            int currentDigit = res % 10;
            res /= 10;
            digitCount[currentDigit]++;
            if (currentDigit < lastDigit) {
                int swapDigit = currentDigit + 1;
                while (swapDigit < 10 && digitCount[swapDigit] == 0) swapDigit++;
                res = res * 10 + swapDigit;
                digitCount[swapDigit]--;
                for (int i = 0; i < 10; i++) {
                    while (digitCount[i] > 0) {
                        res = res * 10 + i;
                        digitCount[i]--;
                    }
                }
                if (res > 2127283647) return -1;
                else return res;
            }
            lastDigit = currentDigit;
        }
        return -1;
    }
};
