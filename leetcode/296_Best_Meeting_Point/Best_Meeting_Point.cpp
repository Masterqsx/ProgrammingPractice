class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> x, y;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 1){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return mindis(x) + mindis(y);
    }
    int mindis(vector<int>& x){
        int lo = 0, hi = x.size()-1, dis = 0;
        while (lo < hi)
            dis += x[hi--] - x[lo++];
        return dis;
    }
};