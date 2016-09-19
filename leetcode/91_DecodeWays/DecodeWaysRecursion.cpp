class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return s[0]=='0'?0:1;
        if(s.size()==2){
            if((s[0]=='0')||(s[0]>'2')&&(s[1]=='0')) return 0;
            else if(((s[0]=='1')&&(s[1]!='0'))||((s[0]=='2')&&((s[1]-'0')<=6)&&(s[1]!='0'))) return 2;
            else return 1;
        }
        int a=(s[0]=='0'?0:1);
        int b=(((s[0]!='0')&&((s[0]=='1')||(s[0]=='2')&&(s[1]<='6')))?1:0);
        return (a==0?0:numDecodings(s.substr(1)))+(b==0?0:numDecodings(s.substr(2)));
    }
};