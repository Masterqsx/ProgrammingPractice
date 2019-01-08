class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int dp[A.size()][A.size()];
        unordered_map<int, int> check = unordered_map<int, int>();
        for (int i = 0; i < A.size() ; i++) {
            check[A[i]] = i;
        }
        memset(dp, 0, sizeof(int) * A.size() * A.size());
        int res = 0;
        for (int i = 1; i < A.size(); i++) {
            for (int j = i - 1; j >= 0 && A[i] - A[j] < A[j]; j--) {
                if (check.find(A[i] - A[j]) != check.end()) {
                    dp[j][i] = dp[check[A[i] - A[j]]][j] + 1;
                    res = max(res, dp[j][i]);
                }
            }
        }
        return res == 0 ? res : res + 2;
    }
};
