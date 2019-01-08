class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() == b.length()) return a == b ? -1 : a.length();
        return a.length() > b.length() ? a.length() : b.length();
    }
};
