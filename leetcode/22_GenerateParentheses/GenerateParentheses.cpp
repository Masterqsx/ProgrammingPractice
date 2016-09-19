class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return recursive(n);
    }
    vector<string> recursive(int n){
        vector<string> re;
        if(n==0){
            re.push_back(string(""));
            return re;
        }
        if(n==1){
            re.push_back(string("()"));
            return re;
        }
        for(int i=1;i<2*n;i+=2){
            vector<string> l=recursive((i-1)/2);
            vector<string> r=recursive((2*n-1-i)/2);
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    string s;
                    ((((s+='('))+=l[j])+=')')+=r[k];
                    re.push_back(s);
                }
            }
        }
        return re;
    }
};