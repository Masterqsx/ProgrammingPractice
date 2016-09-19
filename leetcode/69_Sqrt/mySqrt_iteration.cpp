class Solution {
  public:
    int mySqrt(int x){
      if(x<0)
        return -1;
      else if((x==0)||(x==1))
        return x;
      else{
        int low=1;
        int high=x;
        int mid=low+(high-low)/2;
        while(low<high){   
          mid=low+(high-low)/2;
          if(mid==x/mid)
            return mid;
          else if(mid>x/mid)
            high=mid;
          else
            low=mid+1;
        }
        return low-1;
      }
    }
};
