class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty() || words[0].empty()) return vector<int>();
        int w_len = words[0].size(), w_n = words.size(), n = s.size();
        vector<int> res;
        unordered_map<string, int> dict;
        for (string word : words) dict[word]++;
        for (int i=0;i<w_len;i++){
            unordered_map<string, int> seen;
            int count = w_n, start = i;
            for (int j=i;j<=n-w_len;j+=w_len){
                string cur = s.substr(j, w_len);
                if (dict.count(cur) == 1){
                    count--;
                    seen[cur]++;
                    if (seen[cur] > dict[cur]){
                        while (s.substr(start, w_len) != cur){
                            seen[s.substr(start, w_len)]--;
                            start += w_len;
                            count++;
                        }
                        seen[cur]--;
                        start += w_len;
                        count++;
                    }
                    if (count == 0){
                        seen[s.substr(start, w_len)]--;
                        count++;
                        start += w_len;
                        res.push_back(j-w_n * w_len + w_len);
                    }
                }
                else{
                    count = w_n;
                    start = j + w_len;
                    seen.clear();
                }
            }
        }
        return res;
    }
};