class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;
        int lo = 2, hi = num;
        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            if (mid * mid == num) return true;
            else if (mid < num/mid) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};