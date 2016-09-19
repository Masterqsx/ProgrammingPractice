class Solution {
public:
    int reverse(int x) {
        long old = x, ne = 0;
        old = abs(old);
        while (old != 0){
            ne *= 10;
            ne += old % 10;
            if (ne > numeric_limits<int>::max()) return 0;//pay attention to overflow
            old /= 10;
        }
        return (x >= 0) ? ne : -ne;
    }
};