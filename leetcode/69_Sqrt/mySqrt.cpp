class Solution {
  public:
    double target;
      int mySqrt(int x) {
        target=(double)x;
          if(x<0)
            return -1;
          else if((x==0)||(x==1))
            return x;
          return (int)mySqrtRecursion(0.0,(double)x);
      }
      double mySqrtRecursion(double low, double high){
        double middle=low+(high-low)/2;
        if(abs(middle*middle-target)<=0.01)
          return middle;
        else if(middle>=target/middle)
          return mySqrtRecursion(low,middle);
        else
          return mySqrtRecursion(middle,high);
      }
};
