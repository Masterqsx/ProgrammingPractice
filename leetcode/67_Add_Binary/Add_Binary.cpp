class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty()) return string("0");
        int ai = a.size()-1, bi = b.size()-1, carry = 0, sum = 0;
        string res;
        while (ai >=0 || bi >= 0){
            sum = (ai >= 0 ? a[ai]-'0' : 0) + (bi >= 0 ? b[bi]-'0' : 0) + carry;
            res.insert(res.begin(), sum%2 + '0');
            carry = sum / 2;
            if (ai >= 0) ai--;
            if (bi >= 0) bi--;
        }
        if (carry > 0) res.insert(res.begin(), carry + '0');
        return res;
    }
};