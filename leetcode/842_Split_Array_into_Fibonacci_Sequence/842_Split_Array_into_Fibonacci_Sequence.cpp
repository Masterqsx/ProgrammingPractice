class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res = vector<int>();
        bp(S, res);
        return res;
    }
    bool bp(string str, vector<int>& res) {
        if (str.size() <= 0 && res.size() > 2) return true;
        for (int sz = 1; sz <= str.length(); sz++) {
            if (stol(str.substr(0, sz)) > 2147483647) return false;
            if (res.size() < 2 || res[res.size() - 1] + res[res.size() - 2] == stoi(str.substr(0, sz))) {
                if (str[0] == '0' && sz > 1) return false;
                res.push_back(stoi(str.substr(0, sz)));
                if (bp(str.substr(sz), res)) return true;
                res.pop_back();
            }
        }
        return false;
    }
};
