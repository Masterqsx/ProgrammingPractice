class Solution {
public:
    void backtracking(vector<vector<string>> &res, vector<string> &co, vector<vector<bool>> &pal, int start, string &s){
        if (start >= s.size()){
            res.push_back(co);
            return;
        }
        for (int i=start;i<s.size();i++){
            if (s[i] == s[start] && (i-start<2 || pal[start+1][i-1])){
                pal[start][i] = true;
                co.push_back(s.substr(start, i-start+1));
                backtracking(res, co, pal, i+1, s);
                co.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> co;
        vector<vector<bool> > pal = vector<vector<bool> >(s.size(), vector<bool>(s.size(), false));
        backtracking(res, co, pal, 0, s);
        return res;
    }
};