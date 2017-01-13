class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        int sum = 0, res = 0, cur = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            cur += i * A[i];
        }
        res = cur;
        for (int i = 1; i < A.size(); i++) {
            cur = cur - A.size() * (A[A.size() - i]) + sum;
            res = max(res, cur);
        }
        return res;
    }
};
