class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int b=0;
        int e=matrix.size()-1;
        int i,j,temp,next,x,y,nx,ny;
        while(b<e){
            i=b;
            for(j=b;j<e;j++){
                x=i;
                y=j;
                next=matrix[x][y];
                for(int k=0;k<4;k++){
                    nx=y;
                    ny=matrix.size()-1-x;
                    temp=matrix[nx][ny];
                    matrix[nx][ny]=next;
                    x=nx;
                    y=ny;
                    next=temp;
                }
            }
            b++;
            e--;
        }
    }
};