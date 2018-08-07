class Solution {
public:
    bool validate(string l, string r) {
        if (l.length() > 1 && l[0] == '0') return false;
        if (r.length() > 0 && r[r.length() - 1] == '0') return false;
        return true;
    }
    void backTracking(vector<string>& strList, vector<string>& res, string tempStr, int index) {
        if (index == 2) {
            res.push_back(tempStr);
            return;
        }
        string str = strList[index];
            for (int i = 1; i <= str.length(); i++) {
                if (validate(str.substr(0, i), str.substr(i))) {
                    string temp = tempStr;
                    temp += str.substr(0, i) + (i == str.length() ? "" : ".") + str.substr(i);
                    if (index == 0) temp = "(" + temp + ", ";
                    else temp += ")";
                    backTracking(strList, res, temp, index + 1);
                }
            }
    }
    
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.length() - 2);
        vector<string> res = vector<string>();
        for (int i = 1; i < S.length(); i++) {
            vector<string> temp = {S.substr(0, i), S.substr(i)};
            backTracking(temp, res, string(), 0);        
        }
        
        return res;
    }
};
