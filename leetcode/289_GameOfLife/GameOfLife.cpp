class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0) return;
        if(board[0].size()==0) return;
        int m=board.size(),n=board[0].size(),i=0,j=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                int count=0,p=0,q=0;
                for(p=max(i-1,0);p<=min(i+1,m-1);p++){
                    for(q=max(j-1,0);q<=min(j+1,n-1);q++){
                        if((p==i)&&(q==j)) continue;
                        if((board[p][q]&1)==1) count++;
                    }
                }
                if((count==3)||((count==2)&&((board[i][j]&1)==1))) board[i][j]|=2;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if((board[i][j]&2)==2) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};