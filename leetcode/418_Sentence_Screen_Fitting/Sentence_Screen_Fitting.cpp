class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> i_mark = vector<int>(sentence.size(), -1);
        vector<int> r_mark = vector<int>(sentence.size(), -1);
        int i = 0, j = 0, k = 0, res = 0;
        while (i < rows){
            j = cols;
            if (i_mark[k] != -1){
                res += (rows - i) / (i - i_mark[k]) * (res - r_mark[k]);
                i += (rows - i) / (i - i_mark[k]) * (i - i_mark[k]);
                if ((rows - i) % (i - i_mark[k]) == 0) return res;
            }
            else {
                i_mark[k] = i;
                r_mark[k] = res;
            }
            while (j >= sentence[k].size() && j > 0){
                j -= sentence[k].size() + 1;
                k++;
                if (k == sentence.size()) {
                    res++;
                    k = 0;
                }
            }
            i++;
        }
        return res;
    }
};
