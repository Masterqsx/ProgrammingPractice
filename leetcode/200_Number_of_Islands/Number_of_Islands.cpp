class Solution {
public:
    int len;
    int wid;
    void spread(vector<vector<char>> &grid, int i, int j){
        if(i<0 || i>=len || j<0 || j>=wid || grid[i][j]=='0') return;
        grid[i][j] = '0';
        spread(grid, i-1, j);
        spread(grid, i+1, j);
        spread(grid, i, j-1);
        spread(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        len = grid.size();
        wid = grid[0].size();
        int res = 0;
        for (int i=0;i<len;i++){
            for (int j=0;j<wid;j++){
                if (grid[i][j] == '1'){
                    res++;
                    spread(grid, i, j);
                }
            }
        }
        return res;
    }
};