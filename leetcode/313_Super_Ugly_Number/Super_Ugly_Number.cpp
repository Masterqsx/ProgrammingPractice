class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (primes.empty() || n < 1) return 1;
        int k = primes.size(), index[k] = {0}, nums[n+1] = {0};
        nums[0] = 1;
        for (int i=1;i<=n;i++){
            int nb = INT_MAX;
            for (int j=0;j<k;j++) nb = min(primes[j]*nums[index[j]], nb);
            nums[i] = nb;
            for (int j=0;j<k;j++) if (nb%primes[j]==0) index[j]++;
        }
        return nums[n-1];
    }
};