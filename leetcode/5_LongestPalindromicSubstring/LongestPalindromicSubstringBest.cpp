class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.size();
        if((size==0)||(size==1)) return s;
        string T=preProcess(s,size);
        int* p=new int[size];
        memset(p,0,size*sizeof(int));
        int C=0,R=0,ma=0,ma_c=0;
        for(int i=1;i<size-1;i++){
            int i_mirror=2*C-i;
            p[i]=(R>i)?min(R-i,p[i_mirror]):0;
            while(T[i+p[i]+1]==T[i-p[i]-1]) p[i]++;
            if(i+p[i]>R){
                C=i;
                R=i+p[i];
                if(p[i]>ma){
                    ma=p[i];
                    ma_c=i;
                }
            }
        }
        string re=T.substr(ma_c-ma,2*ma+1);
        delete [] p;
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