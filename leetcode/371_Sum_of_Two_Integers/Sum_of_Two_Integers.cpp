class Solution {
public:
    int getSum(int a, int b) {
        int l = 0, r = 0, c = 0, re = 0, sum = 0;
        for (int i=0;i<sizeof(int) * 8;i++){
            l = a & (1 << i);
            r = b & (1 << i);
            re = (re | (l ^ r ^ c));
            c = ((c & (l ^ r)) | (l & r)) << 1;
        }
        return re;
    }
};