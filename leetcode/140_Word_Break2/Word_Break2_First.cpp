class Solution {
public:
    void backtracking(vector<string> &res, string &cob, int start, string s, unordered_set<string> &wordDict){
        if (start >= s.size()){
            res.push_back(cob);
            return;
        }
        for (int i=start;i<s.size();i++){
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
                backtracking(res, cob, i+1, s, wordDict);
                cob.erase(index, len);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string cob;
        backtracking(res, cob, 0, s, wordDict);
        return res;
    }
};