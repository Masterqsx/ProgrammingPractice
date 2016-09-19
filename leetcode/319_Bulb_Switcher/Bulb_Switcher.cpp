class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 0) return 0;
        int count = 0;
        for (int i=1;i<(sqrt(n) + 1);i++){
            if (i * i <= n) count++;
        }
        return count;
    }
};