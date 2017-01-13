class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2){
            int min_d = words.size(), cur = -1;
            for (int i = 0;i < words.size();i++){
                if (words[i] == word1) {
                    if (cur == -1) cur = i;
                    else {
                        min_d = min(min_d, i - cur);
                        cur = i;
                    }
                }
            }
            return min_d;
        }
        else {
            int min_d = words.size(), cur1 = -1, cur2 = -1;
            for (int i = 0;i < words.size();i++){
                if (words[i] == word1) cur1 = i;
                else if (words[i] == word2) cur2 = i;
                if (cur1 != -1 && cur2 != -1){
                    min_d = min(abs(cur1-cur2), min_d);
                }
            }
            return min_d;
        }
    }
};
