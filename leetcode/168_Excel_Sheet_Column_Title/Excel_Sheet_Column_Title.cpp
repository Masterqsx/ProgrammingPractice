class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) return string();
        string base;
        for (int i = 0;i<26;i++) base += ('A' + i);
        string res;
        base_transform(res, n-1, base);//The core part is "-1"
        return res;
    }
    
    void base_transform(string& res, int n, string& base){
        if (n >= 26) base_transform(res, n/26-1, base); //The core part is "-1"
        res += base[n%26];
    }
};