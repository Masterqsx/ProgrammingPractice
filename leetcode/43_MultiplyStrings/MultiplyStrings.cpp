class Solution {
public:
    string multiply(string num1, string num2) {
        string s=string(num1.size()+num2.size(),'0');
        int s1=num1.size(),s2=num2.size();
        for(int i=s1-1;i>=0;i--){
            for(int j=s2-1;j>=0;j--){
                int level=s1-1-i+s2-1-j;
                int p=c_n(num1[i])*c_n(num2[j]);
                while(p!=0){
                    p+=c_n(s[level]);
                    s[level]=n_c(p%10);
                    p/=10;
                    level++;
                }
            }
        }
        string re;
        bool flag=false;
        for(int i=s.size()-1;i>=0;i--){
            if((!flag)&&(s[i]!='0')){
                flag=true;
                re.push_back(s[i]);
            }
            else if(flag){
                re.push_back(s[i]);
            }
        }
        if(re.size()==0) re.push_back('0');
        return re;
    }
    int c_n(char c){
        return c-'0';
    }
    char n_c(int n){
        return n+'0';
    }
};