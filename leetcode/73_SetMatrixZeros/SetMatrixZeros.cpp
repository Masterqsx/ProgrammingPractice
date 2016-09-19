class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        int fi,fj,m = matrix.size(),n = matrix[0].size();
        bool flag = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(!flag){
                        flag = true;
                        fi = i;
                        fj = j;
                    }
                    else{
                        matrix[fi][j] = 0;
                        matrix[i][fj] = 0;
                    }
                }
            }
        }
        if(!flag) return;
        for(int i=0;i<m;i++){
            if(i == fi) continue;
            if(matrix[i][fj]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(j == fj) continue;
            if(matrix[fi][j]==0){
                for(int i=0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++){
            matrix[i][fj] = 0;
        }
        for(int j=0;j<n;j++){
            matrix[fi][j] = 0;
        }
    }
};