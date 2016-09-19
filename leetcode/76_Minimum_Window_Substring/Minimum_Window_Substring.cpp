class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return string();
        unordered_map<char, int> dict;
        for (char c : t) dict[c]++;
        int sz = s.size(), tz = t.size(), count = 0, start = 0, min_start = 0, len = INT_MAX;
        unordered_map<char, int> seen;
        for (int i=0;i<=sz;i++){
            if (count != tz){
                if (dict.count(s[i]) == 1){
                    if (dict[s[i]] > seen[s[i]]) count++;
                    seen[s[i]]++;
                }
            }
            else{
                while (i > start && (dict.count(s[start]) == 0 || dict[s[start]] < seen[s[start]])){
                    if (dict.count(s[start]) == 1) seen[s[start]]--;
                    start++;
                }
                if (i - start < len){
                    min_start = start;
                    len = i - start;
                }
                i--;
                seen[s[start]]--;
                start++;
                count--;
            }
        }
        if (len == INT_MAX) return string();
        else return s.substr(min_start, len);
    }
};