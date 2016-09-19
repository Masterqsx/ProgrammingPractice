class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        if((size==0)||(size==1)) return s;
        char** dp=new char*[3];
        dp[0]=new char[size];
        dp[1]=new char[size];
        dp[2]=new char[size];
        int lo=0,hi=0;
        for(int step=1;step<=size;step++){//step should be no larger than s.size()
            for(int i=0;i<size;i++){
                if((i+step-1)>=size) continue;
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
        delete dp[0];
        delete dp[1];
        delete dp[2];
        delete [] dp;
        return s.substr(lo,hi-lo+1);
    }
};