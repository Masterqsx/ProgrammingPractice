class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.empty()) return false;
        int sz = (int)str.size() / 2;
        while (sz > 0) {
            if ((int)str.size() % sz == 0) {
                bool flag = true;
                for (int i = 0;i < str.size() - sz;i += sz) {
                    if (str.substr(i, sz) != str.substr(i + sz, sz)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
            sz--;
        }
        return false;
    }
};
