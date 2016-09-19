class Solution {
  public:
    int mySqrt(int x){
      double it=x;
      if(x<0)
        return -1;
      else if((x==0)||(x==1))
        return x;
      else{
        while((it*it-x)>=0.4){
          it=it/2+x/it/2;
        }
      }
      return (int)it;
    }
};
