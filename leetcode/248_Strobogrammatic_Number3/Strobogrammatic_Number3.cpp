class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        find(low, high, "", res);
        find(low, high, string("0"), res);
        find(low, high, string("1"), res);
        find(low, high, string("8"), res);
        return res;
    }
    void find(string lo, string hi, string nb, int& res){
        if (nb.size() >= lo.size() && nb.size() <= hi.size()){
            if ((nb.size() == lo.size() && lo.compare(nb) > 0) || (nb.size() == hi.size() && hi.compare(nb) < 0))
                return;
            if (!(nb.size() > 1 && nb[0] == '0')) res++;
        }
        if (nb.size()+2 > hi.size()) return;
        find(lo, hi, "0"+nb+"0", res);
        find(lo, hi, "1"+nb+"1", res);
        find(lo, hi, "8"+nb+"8", res);
        find(lo, hi, "6"+nb+"9", res);
        find(lo, hi, "9"+nb+"6", res);
    }
};