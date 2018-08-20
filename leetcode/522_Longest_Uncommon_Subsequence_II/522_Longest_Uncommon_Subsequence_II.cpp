class Solution {
public:
    bool valid(string sub, string str) {
        if (sub.length() > str.length()) return true;
        int index = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == sub[index]) index++;
        }
        return index != sub.length();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string l, string r) {return l.length() > r.length();});
        for (int i = 0; i < strs.size(); i++) {
            bool flag = true;
            for (int j = 0; strs[j].length() >= strs[i].length() && j < strs.size() ; j++) {
                if (j == i) continue;
                flag = flag && valid(strs[i], strs[j]);
            }
            if (flag) return strs[i].length();
        }
        return -1;
    }
};
