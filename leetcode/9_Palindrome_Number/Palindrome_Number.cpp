class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long mask = 1; //really be carefule about overflow problem
        while (mask <= x) mask *= 10;
        mask /= 10;
        while (mask > 1){
            if (x/mask != x%10) return false;
            x %= mask;
            x /= 10;
            mask /= 100;
        }
        return true;
    }
};