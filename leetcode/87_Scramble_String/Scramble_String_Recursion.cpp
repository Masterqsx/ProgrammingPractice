class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string s1_temp(s1), s2_temp(s2);
        sort(s1_temp.begin(), s1_temp.end());
        sort(s2_temp.begin(), s2_temp.end());
        if (s1_temp != s2_temp) return false;
        int end = s1.size();
        for(int i=1;i<end;i++){
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i, end-i);
            if (isScramble(s11, s2.substr(0, i)) && isScramble(s12, s2.substr(i, end-i))) return true;
            if (isScramble(s12, s2.substr(0, end-i)) && isScramble(s11, s2.substr(end-i, i))) return true;
        }
        return false;
    }
};