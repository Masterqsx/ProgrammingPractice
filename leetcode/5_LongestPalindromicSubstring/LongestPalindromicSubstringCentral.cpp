class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        if((size==0)||(size==1)) return s;
        string T=preProcess(s,size);
        int p=0;
        int ma=0,ma_c=0;
        for(int i=1;i<size-1;i++){
            p=0;
            while(T[i+p+1]==T[i-p-1]) p++;
            if(p>ma){
                ma=p;
                ma_c=i;
            }
        }
        string re=T.substr(ma_c-ma,2*ma+1);
        for(int i=0;i<re.size();i++){
            if(re[i]=='#'){
                re.erase(i,1);
                i--;
            }
        }
        return re;
    }
    string preProcess(string& s,int& size){
        string re;
        re+='^';
        for(int i=0;i<size;i++){
            re.push_back('#');
            re.push_back(s[i]);
        }
        re+="#$";
        size=re.size();
        return re;
    }
};