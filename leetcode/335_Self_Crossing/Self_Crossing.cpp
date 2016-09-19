class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) return false;
        int sz = x.size();
        for (int i=0;i<sz;i++){
            if (i+3<sz && x[i]>=x[i+2] && x[i+3]>=x[i+1]) return true;
            if (i+4<sz && x[i+1] == x[i+3] && x[i]+x[i+4]>=x[i+2]) return true;
            if (i+5<sz && x[i+2]<=x[i]+x[i+4] && x[i+1]+x[i+5]>=x[i+3] && x[i+2]>=x[i+4] && x[i+3]>=x[i+1]) return true;
        }
        return false;
    }
};