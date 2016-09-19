class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if((s.size()==0)||(s.size()==1)) return s.size();
        string existed;
        int max=0,cur=0,pos=0;
        for(int i=0;i<s.size();i++){
            if((!existed.empty())&&((pos=existed.find(s[i]))!=-1)){
                existed=existed.substr(pos+1);
                existed.push_back(s[i]);
                cur=existed.size();
            }
            else{
                existed.push_back(s[i]);
                cur++;
            }
            if(cur>max) max=cur;
        }
        return max;
    }
    
};