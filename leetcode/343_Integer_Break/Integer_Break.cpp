class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        if (n == 3) return 2;
        for (int i = 2; i <= n/2;i++){
            int t1 = pow(n/i, i-1) * (n/i+n%i);
            int t2 = pow(n/i+1, i-1) * (n - (n/i+1) * (i-1));
            res = max(t1, res);
            res = max(t2, res);
        }
        return res;
    }
};