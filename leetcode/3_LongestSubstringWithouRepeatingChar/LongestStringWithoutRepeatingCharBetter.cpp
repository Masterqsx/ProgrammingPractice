class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if((s.size()==0)||(s.size()==1)) return s.size();
        int max=0,cur=0,lo=0;
        for(int i=0;i<s.size();i++){
            if(lo<i){
                int j=0;
                for(j=lo;j<i;j++){
                    if(s[j]==s[i]) break;
                }
                if(j!=i){
                    cur=i-j;
                    lo=j+1;
                }
                else cur++;
            }
            else cur++;
            if(cur>max) max=cur;
        }
        return max;
    }
};