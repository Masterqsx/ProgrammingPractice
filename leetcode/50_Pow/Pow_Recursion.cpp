class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        if (x == -1) return n%2==0 ? 1 : -1;
        double res = myPow_helper(x, abs(n));
        if (n < 0) res = 1 / res;
        return res;
    }
    double myPow_helper(double x, int n){
        if (n == 0) return 1;
        double half = myPow_helper(x, n / 2);
        half *= half;
        if (n % 2 != 0) return half * x;
        else return half;
    }
};