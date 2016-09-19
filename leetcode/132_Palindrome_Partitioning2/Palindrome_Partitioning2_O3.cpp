class Solution {
public:
    int minCut(string s) {
        bool pal[s.size()][s.size()] = {{0}};
        int cut[s.size()][s.size()] = {{0}};
        for (int step=0;step<s.size();step++){
            for (int i=0;i+step<s.size();i++){
                if (step == 0){
                    pal[i][i] = true;
                    cut[i][i] = 0;
                }
                else if (step == 1){
                    pal[i][i+1] = s[i] == s[i+1];
                    cut[i][i+1] = pal[i][i+1] == true?0:1;
                }
                else {
                    pal[i][i+step] = s[i] == s[i+step] && pal[i+1][i+step-1];
                    cut[i][i+step] = pal[i][i+step]?0:step;
                    if (!pal[i][i+step]) {
                        for (int j=i;j<i+step;j++)
                            cut[i][i+step] = min(cut[i][i+step], cut[i][j]+cut[j+1][i+step]+1);
                    }
                }
            }
        }
        return cut[0][s.size()-1];
    }
};