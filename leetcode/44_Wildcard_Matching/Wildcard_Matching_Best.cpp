class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, istar = -1, jstar = -1, sl = s.size(), pl = p.size();
        while (i < sl){
            if(p[j] == '*'){
                istar = i;
                jstar = j++;
            }
            else if (s[i] == p[j] || p[j] == '?'){
                i++;
                j++;
            }
            else if(jstar >= 0){
                i = ++istar;
                j = jstar;
            }
            else
                return false;
        }
        while (j < pl && p[j] == '*') j++;
        return j == pl;
    }
};