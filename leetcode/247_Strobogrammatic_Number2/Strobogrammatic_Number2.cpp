class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n % 2 != 0){
            backtracking(res, string("0"), n-1);
            backtracking(res, string("1"), n-1);
            backtracking(res, string("8"), n-1);
        }
        else
            backtracking(res, string(), n-1);
        return res;
    }
    void backtracking(vector<string>& res, string nb, int n){
        if (n <= 0){
            res.push_back(nb);
            return;
        }
        backtracking(res, string('8'+nb+'8'), n-2);
        backtracking(res, string('1'+nb+'1'), n-2);
        if (n > 2) backtracking(res, string('0'+nb+'0'), n-2);
        backtracking(res, string('6'+nb+'9'), n-2);
        backtracking(res, string('9'+nb+'6'), n-2);
    }
};