class Solution {
public:
    int titleToNumber(string s) {
        char begin = 'A' - 1;
        int res = 0;
        for (char c : s){
            res = res * 26 + (c - begin);
        }
        return res;
    }
};