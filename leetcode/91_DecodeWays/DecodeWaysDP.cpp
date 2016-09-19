class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return isvalid(s);
        int dp[s.size()]={0};
        dp[0]=isvalid(s.substr(0,1));
        dp[1]=dp[0]*isvalid(s.substr(1,1))+isvalid(s.substr(0,2));
        for(int i=2;i<s.size();i++){
            dp[i]=dp[i-1]*isvalid(s.substr(i,1))+dp[i-2]*isvalid(s.substr(i-1,2));
        }
        return dp[s.size()-1];
    }
    int isvalid(string s){
        if((s.size()==0)||(s.size()>2)) return 0;
        if(s.size()==1) return (s[0]!='0'?1:0);
        return (((s[0]=='1')||(s[0]=='2')&&(s[1]<='6'))?1:0);
    }
};