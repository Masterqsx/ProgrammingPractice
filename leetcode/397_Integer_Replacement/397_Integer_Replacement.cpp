class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long num = (long)n;
        while (num > 3) {
            if (num % 4 == 1) num -= 1;
            else if (num % 4 == 3) num += 1;
            else num /= 2;
            res += 1;
        }
        if (num == 3) return res + 2;
        else if (num == 2) return res + 1;
        else return res;
    }
};
