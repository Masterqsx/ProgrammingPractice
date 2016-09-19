class Solution {
public:
    void backtracking(vector<string> &res, string &cob, int start, string s, unordered_set<string> &wordDict, vector<bool> &dp){
        if (start >= s.size()){
            res.push_back(cob);
            return;
        }
        for (int i=start;i<s.size();i++){
            if (!dp[i+1]) continue;
            if (wordDict.find(s.substr(start, i-start+1))!=wordDict.end()){
                int index = 0, len = 0;
                if (cob.empty()){
                    cob += s.substr(start, i-start+1);
                    len = i-start+1;
                }
                else{
                    index = cob.size();
                    cob += " " + s.substr(start, i-start+1);
                    len = i-start+2;
                }
                backtracking(res, cob, i+1, s, wordDict, dp);
                cob.erase(index, len);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string cob;
        vector<bool> dp = vector<bool>(s.size()+1, false);
        dp[s.size()] = true;
        for (int i=s.size()-1;i>=0;i--){
            for (int j=i;j<s.size();j++){
                if (dp[j+1] && wordDict.count(s.substr(i, j-i+1))==1){
                    dp[i] = true;
                    break;
                }
            }
        }
        backtracking(res, cob, 0, s, wordDict, dp);
        return res;
    }
};