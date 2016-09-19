class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        if (n == 1) return string(to_string(1));
        bool num[n+1];
        fill_n(num, 10, true);
        int step = 1, quotient = 0, i = 2, count = n;
        for (;i<n;i++) step *= i;
        string res;
        while (count > 0){
            quotient = k / step + 1;
            for (int j = 1; j <= n ; j++){
                if (num[j]) quotient--;
                if (quotient == 0){
                    res += to_string(j);
                    num[j] = false;
                    break;
                }
            }
            k = k % step;
            step /= (i > 1?(--i):1);
            count--;
        }
        return res;
    }
};