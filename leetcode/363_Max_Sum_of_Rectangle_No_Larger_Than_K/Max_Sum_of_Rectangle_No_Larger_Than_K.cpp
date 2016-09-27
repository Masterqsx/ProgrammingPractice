class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int h = matrix.size(), w = matrix[0].size();
        int max_res = INT_MIN;
        int sum[h][w] = {{0}};
        for (int i=0;i<w;i++){
            for (int j=i;j<w;j++){
                set<int> tmp({0});
                int s = 0;
                for (int m=0;m<h;m++) {
                    if (i == 0) {
                        if (j == 0) sum[m][j] = matrix[m][j];
                        else sum[m][j] = sum[m][j-1] + matrix[m][j];
                    }
                    s += (sum[m][j]-(i<=0?0:sum[m][i-1]));
                    auto it = tmp.lower_bound(s-k);
                    if (it != tmp.end()) max_res = max(max_res, s-*it);
                    tmp.insert(s);
                }
            }
        }
        return max_res;
    }
};
