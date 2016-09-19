class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0||x == 1) return 1;
        if (x == -1) return n%2==0?1:-1;
        bool flag = (x >= 0);
        int n_t = n;
        x = abs(x);
        double res = x;
        
        if (n < 0){
            while (n < 1){
                if (x < 1 && res >= numeric_limits<double>::max() * x) return numeric_limits<double>::max();
                if (x > 1 && res < numeric_limits<double>::epsilon()) return 0;
                res /= x;
                n++;
            }
        }
        else{
            while (n > 1){
                if (x > 1 && res >= numeric_limits<double>::max() / x) return numeric_limits<double>::max();
                if (x < 1 && res < numeric_limits<double>::epsilon()) return 0;
                res *= x;
                n--;
            }
        }
        if (flag) return res;
        else if (n_t%2 == 0) return res;
        else return -res;
    }
};