class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size()-1, sz2 = num2.size()-1, cur = 0, count = 0;
        string res;
        while (sz1 >= 0 || sz2 >= 0){
            if (sz1 < 0) {
                cur = (num2[sz2] - '0' + count) % 10;
                count = (num2[sz2] - '0' + count) / 10;
                sz2--;
            }
            else if (sz2 < 0) {
                cur = (num1[sz1] - '0' + count) % 10;
                count = (num1[sz1] - '0' + count) / 10;
                sz1--;
            }
            else {
                cur = (num1[sz1] - '0' + num2[sz2] - '0' + count) % 10;
                count = (num1[sz1] - '0' + num2[sz2] - '0' + count) / 10;
                sz1--;
                sz2--;
            }
            res = to_string(cur) + res;
        }
        if (count != 0) res = to_string(count) + res;
        return res;
    }
};
