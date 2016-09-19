class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> m;
        vector<vector<string> >re;
        unordered_map<string,int>::iterator it;
        for(int i=0;i<strs.size();i++){
            string v=value(strs[i]);
            if((it=m.find(v))!=m.end()){
                re[it->second].push_back(strs[i]);
            }
            else{
                re.push_back(vector<string>(1,strs[i]));
                m[v]=re.size()-1;
            }
        }
        return re;
    }
    string value(string& s){
        int ans[26]={0};
        string re;
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            re+=string(ans[i],'a'+i);
        }
        return re;
    }
};