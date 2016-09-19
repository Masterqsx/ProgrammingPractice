class Solution {
public:
    int myAtoi(string str) {
        long re = 0;
        int i = 0, sz = str.size();
        while (str[i] == ' ' && i < sz) i++;
        bool is_neg = false;
        if (str[i] == '-'){
            is_neg = true;
            i++;
        }
        else if (str[i] == '+') i++;
        while (str[i] >= '0' && str[i] <= '9' && i < sz){
            re *= 10;
            re += str[i] - '0';
            if ((re > 2147483647) && !is_neg) return INT_MAX;
            if ((re > 2147483648) && is_neg) return INT_MIN;
            i++;
        }
        return is_neg?-re:re;
    }
};