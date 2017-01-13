class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int sz = words.size(), min_d = INT_MAX, i1 = -1, i2 = -1;
        for (int i = 0; i < sz; i++){
            if (words[i] == word1) i1 = i;
            else if (words[i] == word2) i2 = i;
            if (i1 != -1 && i2 != -1){
                min_d = min(min_d, abs(i1-i2));
            }
        }
        return min_d;
    }
};
