class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        unordered_set<int> check;
        int temp = n;
        while ((temp = next_n(temp)) != 1){
            if (check.count(temp) != 0) return false;
            check.insert(temp);
        }
        return true;
    }
    int next_n(int n){
        int res = 0;
        while (n > 0){
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
};