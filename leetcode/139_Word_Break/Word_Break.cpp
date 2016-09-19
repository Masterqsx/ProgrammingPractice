class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) return true;
        if (wordDict.empty()) return false;
        bool dp[s.size()+1] = {0};
        dp[0] = true;
        for (int i = 1;i<=s.size();i++){
            for (int j = 0;j<i;j++){
                if (dp[j] &&(wordDict.find(s.substr(j, i-j))!=wordDict.end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};