class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26] = {0}, higher[26] = {0};
        for (char c : s){
            if (c >= 'A' && c <= 'Z') higher[c-'A']++;
            else lower[c-'a']++;
        }
        int res = 0;
        bool flag = false;
        for (int i=0;i<26;i++){
            if (lower[i] % 2 == 0) res += lower[i];
            else {
                res += lower[i]-1;
                flag = true;
            }
            if (higher[i] % 2 == 0) res += higher[i];
            else {
                res += higher[i]-1;
                flag = true;
            }
        }
        if (!flag) return res;
        else return res+1;
    }
};
