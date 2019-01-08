class Solution {
public:
    int reachNumber(int target) {
        long t = abs(target);
        int k = (int)((sqrt(1 + 8 * t) - 1.0) / 2.0);
        while (1) {
            if (k * (k + 1) / 2 >= t && (t - k * (k + 1) / 2) % 2 == 0) break;;
            k++;
        }
        return k;
    }
};
