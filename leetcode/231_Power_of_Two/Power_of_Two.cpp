class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int rightmost = (n & (-n));
        if (rightmost == 0) return false;
        n = n & (~rightmost);
        if (n > 0) return false;
        else return true;
    }
};