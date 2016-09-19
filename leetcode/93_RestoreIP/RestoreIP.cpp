class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        string a;
        backtracking(re,a,s,4,0);
        for(auto&& str:re){
            str.erase(0,1);
        }
        return re;
    }
    void backtracking(vector<string>& re,string cur,string s,int level,int start){
        if(level==1){
            if(start<s.size()&&start>=s.size()-3&&isvalid(s.substr(start))){
                (cur+=".")+=s.substr(start);
                re.push_back(cur);
            }
            return;
        }
        for(int i=start+1;i<start+4;i++){
            if(s.size()-i>level*3) continue;
            string temp(cur);
            string st=s.substr(start,i-start);
            if(isvalid(st)) (temp+=".")+=st;
            else continue;
            backtracking(re,temp,s,level-1,i);
        }
    }
    bool isvalid(string s){
        if(s.empty()||s.size()>3) return false;
        int num=0;
        stringstream convert(s);
        if(!(convert>>num)) num=0;
        if(num>255||s[0]=='0'&&s.size()>1) return false;//we should prevent similar to "00" or "010" being in the ip
        else return true;
    }
};