class Solution {
public:
    int minCut(string s) {
        bool pal[s.size()][s.size()] = {{0}};
        int cut[s.size()] = {0};
        for (int j=1;j<s.size();j++){
            cut[j] = j;
            for (int i=j;i>=0;i--){
                if (s[i] == s[j] && (j-i<2 || pal[i+1][j-1])){
                    pal[i][j] = true;
                    if (i == 0) cut[j] = 0;
                    else cut[j] = min(cut[j], cut[i-1]+1);
                }
            }
        }
        return cut[s.size()-1];
    }
};