class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int> >record(m+1,vector<int>(n+1,0));
        record[0][1]=1;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                record[i][j]=obstacleGrid[i-1][j-1]==1?0:record[i-1][j]+record[i][j-1];
            }
        }
        return record[m][n];
    }
    
    
};