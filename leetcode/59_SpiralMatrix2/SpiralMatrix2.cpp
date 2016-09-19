class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > re = vector<vector<int> >(n,vector<int>(n,0));
        int b=0,e=n-1,temp=1,i,j;
        while(b<=e){
            re[b][b]=temp;
            for(i=b,j=b;j<e;j++){
                re[i][j]=temp;
                temp++;
            }
            for(i=b,j=e;i<e;i++){
                re[i][j]=temp;
                temp++;
            }
            for(i=e,j=e;j>b;j--){
                re[i][j]=temp;
                temp++;
            }
            for(i=e,j=b;i>b;i--){
                re[i][j]=temp;
                temp++;
            }
            b++;
            e--;
        }
        return re;
    }
};