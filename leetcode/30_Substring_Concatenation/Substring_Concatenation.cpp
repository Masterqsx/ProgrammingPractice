class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty() || words[0].empty()) return vector<int>();
        int w_len = words[0].size(), w_n = words.size(), n = s.size();
        vector<int> res;
        unordered_map<string, int> dict;
        for (string word : words) dict[word]++;
        for (int i=0;i<=(n-w_len*w_n);i++){
            unordered_map<string, int> seen;
            int j;
            for (j=0;j<w_n;j++){
                string cur = s.substr(i+j*w_len, w_len);
                if (dict.count(cur) == 1){
                    seen[cur]++;
                    if (seen[cur] > dict[cur]) break;
                }
                else break;
            }
            if (j == w_n) res.push_back(i);
        }
        return res;
    }
};