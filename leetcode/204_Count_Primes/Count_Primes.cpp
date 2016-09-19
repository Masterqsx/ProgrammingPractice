class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool search[n];
        fill_n(search, n, true);
        for (int i = 2; i < n/2+1 ; i++){
            if (!search[i]) continue;
            for (int j = 2; i * j < n;j++) search[i*j] = false;
        }
        int count = 0;
        for (int i = 2;i<n;i++){
            if (search[i]) count++;
        }
        return count;
    }
};