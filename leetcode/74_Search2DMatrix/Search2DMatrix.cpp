class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        
        int m=matrix.size(),n=matrix[0].size(),i;
        for(i=0;i<m;i++){
            if(matrix[i][n-1]>target)
                break;
            if(matrix[i][n-1]==target)
                return true;
        }
        if((i==m)&&(matrix[m-1][n-1]<target))
            return false;
        if(matrix[i][0]>target)
            return false;
        else{
            if(matrix[i][0]==target)
                return true;
            return binarysearch(matrix[i],0,n-1,target);
        }
        
    }
    bool binarysearch(vector<int> row,int lo, int hi, int target){
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(row[mid]==target){
                return true;
            }
            else if(row[mid]<target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};