class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > record(triangle.size(),vector<int>(triangle[triangle.size()-1].size()+2,INT_MAX));
        record[0][1]=triangle[0][0];
        int result=triangle.size()==1?record[0][1]:INT_MAX;
        for(int level=1;level<triangle.size();level++){
            for(int j=1;j<=triangle[level].size();j++){
                record[level][j]=triangle[level][j-1]+min(record[level-1][j-1],record[level-1][j]);//we only consider the number before and in the same column. Not consider the next column
                if(level==triangle.size()-1){
                    result=result<record[level][j]?result:record[level][j];
                }
            }
        }
        return result;
    }
};