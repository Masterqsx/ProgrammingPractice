class Solution {
public:
    int numTrees(int n) {
        vector<int> dp=vector<int>(n+1,1);
        cout<<dp[0]<<endl;
        for(int i=2;i<=n;i++){
            dynamicProgramming(dp,i);
        }
        return dp[n];
    }
    void dynamicProgramming(vector<int>& dp,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=dp[i]*dp[n-i-1];
        }
        dp[n]=sum;
    }
};