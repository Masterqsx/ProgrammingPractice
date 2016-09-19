class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> match;
        int count = 0;
        match['I'] = 1;
        match['V'] = 5;
        match['X'] = 10;
        match['L'] = 50;
        match['C'] = 100;
        match['D'] = 500;
        match['M'] = 1000;
        for (int i = 0; i < s.size(); i++){
            if (i == s.size() -1 || match[s[i]] >= match[s[i+1]])
                count += match[s[i]];
            else
                count -= match[s[i]];
        }
        return count;
    }
};