class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        int n = 0;
        while (n < strs[0].size()){
            char c = strs[0][n];
            for (int i=1;i<strs.size();i++){
                if (strs[i][n] != c) return res;
            }
            res += c;
            n++;
        }
        return res;
    }
};