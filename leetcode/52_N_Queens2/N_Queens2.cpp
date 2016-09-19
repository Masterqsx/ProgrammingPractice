class Solution {
public:
    int totalNQueens(int n) {
        unsigned int limit = 1;
        int re = 0;
        for (int i = 0;i < n - 1;i++)
            limit = (limit << 1) + 1;
        recursive(0, 0, 0, 0, limit, re, n);
        return re;
    }
    void recursive(unsigned int rw, unsigned int ud, unsigned dd, unsigned int level, unsigned int limit, int &re, int n){
        if (level >= n){
            re++;
            return;
        }
        ud = ud << 1 & limit;
        dd = dd >> 1 & limit;
        unsigned int pos = ~(rw | dd | ud) & limit;
        for(unsigned int mask = 1 << (n - 1);mask > 0;mask = mask >> 1){
            if ((pos & mask ) > 0){
                recursive((rw | (pos & mask)), (ud | (pos & mask)), (dd | (pos & mask)), level + 1, limit, re, n);
            }
        }
    }
};