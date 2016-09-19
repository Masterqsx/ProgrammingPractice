class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size(), dp[sizeA+1][sizeB+1];
        for (int i = 0; i <= sizeA; i++){
            for (int j = 0; j <= sizeB; j++){
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(max(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
            }
        }
        return dp[sizeA][sizeB];
    }
};
