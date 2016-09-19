class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty()) return false;
        int lo = 0, hi = num.size()-1;
        while (lo < hi){
            if (num[lo] == '6' && num[hi] == '9' || num[lo] == '9' && num[hi] == '6'){
                lo++;
                hi--;
                continue;
            }
            if ((num[lo] == '8' && num[hi] == '8') || (num[lo] == '1' && num[hi] == '1') || (num[lo] == '0' && num[hi] == '0')){
                lo++;
                hi--;
                continue;
            }
            return false;
        }
        if (lo == hi && num[lo] != '8' && num[lo] != '1' && num[lo] != '0') return false;
        return true;
    }
};