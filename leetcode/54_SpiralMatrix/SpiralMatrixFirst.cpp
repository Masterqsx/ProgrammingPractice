class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        
        int b_i=0;
        int b_j=0;
        int e_i=matrix.size(); if (e_i==0) return re;
        int e_j=matrix[0].size(); if (e_j==0) return re;
        
        while((b_i<e_i) && (b_j<e_j)){
            int h_f=false;
            int v_f=false;
            int i=b_i;
            int j=b_j;
            for(j=b_j,i=b_i;j<e_j;j++){
                re.push_back(matrix[i][j]);
                h_f=true&&(b_j<e_j-1);
            }
            
            for(j=e_j-1,i=b_i+1;i<e_i;i++){
                re.push_back(matrix[i][j]);
                v_f=true;
            }
            
            for(j=e_j-2,i=e_i-1;j>=b_j&&v_f==true;j--) re.push_back(matrix[i][j]);
            
            for(j=b_j,i=e_i-2;i>b_i&&h_f==true;i--) re.push_back(matrix[i][j]);
            
            b_i++;
            b_j++;
            e_i--;
            e_j--;
        }
        return re;
    }
};