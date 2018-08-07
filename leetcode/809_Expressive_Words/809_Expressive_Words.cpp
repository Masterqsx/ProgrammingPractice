class Solution {
public:
    bool match(string s, string p) {
        int i = 2, j = 2;
        s = "^^" + s + "$";
        p = "^^" + p + "$";
        while (i < s.length() && j < p.length()) {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else if (s[i - 2] == s[i - 1] && s[i - 1] == s[i] || s[i - 1] == s[i] && s[i] == s[i + 1]) i++;
            else return false;
        }
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (string word : words) {
            if (match(S, word)) res++;
        }
        return res;
    }
};
