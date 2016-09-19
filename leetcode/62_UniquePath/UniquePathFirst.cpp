class Solution {//just calculate the combination
public:
    int uniquePaths(int m, int n) {
        double bottom=1,top=1;
        for(double i=1;i<min(m,n);i++){
            bottom*=i;
        }
        for(double i=m+n-2;i>(m+n-2-(min(m,n)-1));i--){
            top*=i;
        }
        return (int)(top/bottom);
    }
};