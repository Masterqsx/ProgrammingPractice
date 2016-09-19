class Solution {
public:
    string longestPalindrome(string s) {
        if((s.size()==0)||(s.size()==1)) return s;
        vector<vector<char> > dp=vector<vector<char> >(3,vector<char>(s.size(),0));
        int lo=0,hi=0;
        for(int step=1;step<=s.size();step++){//step should be no larger than s.size()
            for(int i=0;i<s.size();i++){
                if((i+step-1)>=s.size()) continue;
                int j=i+step-1;
                if(i>=j) dp[(j-i)%3][i]=1;
                else{
                    if(s[i]==s[j]){
                        if(i+1>j-1) dp[(j-i)%3][i]=1;
                        else dp[(j-i)%3][i]=dp[(j-i-2)%3][i+1];
                        if((dp[(j-i)%3][i]==1)&&((j-i)>(hi-lo))){
                            lo=i;
                            hi=j;
                        }
                    }
                    else dp[(j-i)%3][i]=-1;
                }
            }
        }
        return s.substr(lo,hi-lo+1);
    }
};