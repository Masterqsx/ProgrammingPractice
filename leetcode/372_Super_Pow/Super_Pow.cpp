class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 0;
        if (a==1 || a==0) return a;
        int res = 1;
        for (int n : b){
            res = myPow(res, 10) * myPow(a % 1337, n) % 1337;
        }
        return res;
    }
    int myPow(int a, int n){
        if (n == 1) return a % 1337;
        if (n == 0) return 1;
        int half = myPow(a % 1337, n/2);
        if (n % 2 == 0) return half * half % 1337;
        else return (half * half % 1337) * (a % 1337) % 1337;
    }
};