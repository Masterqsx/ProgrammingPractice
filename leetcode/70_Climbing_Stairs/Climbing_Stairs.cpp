class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        int num[n+1] = {0};
        num[0] = 1;
        num[1] = 1;
        for (int i=2;i<=n;i++){
            num[i] = num[i-1] + num[i-2];
        }
        return num[n];
    }
};
