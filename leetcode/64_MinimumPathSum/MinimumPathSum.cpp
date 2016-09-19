class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<int> > re = vector<vector<int> >(grid.size()+1, vector<int>(grid[0].size()+1,INT_MAX));
        re[0][1] = 0;
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                re[i][j]=min(re[i-1][j],re[i][j-1])+grid[i-1][j-1];
            }
        }
        return re[grid.size()][grid[0].size()];
    }
};