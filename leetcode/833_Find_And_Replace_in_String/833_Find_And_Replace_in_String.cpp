class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<int> charIndexes = vector<int>(S.length(), -1);
        for (int i = 0; i < indexes.size(); i++) {
            charIndexes[indexes[i]] = i;
        }
        string res;
        for (int i = 0; i < charIndexes.size(); i++) {
            if (charIndexes[i] == -1) res += S[i];
            else if (sources[charIndexes[i]] == S.substr(i, sources[charIndexes[i]].length())) {
                res += targets[charIndexes[i]];
                i += sources[charIndexes[i]].length() - 1;
            } else res += S[i];
        }
        return res;
    }
};
