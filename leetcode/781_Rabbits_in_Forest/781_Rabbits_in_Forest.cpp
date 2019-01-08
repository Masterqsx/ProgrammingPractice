class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count[1000];
        memset(count, 0, 1000 * sizeof(*count));
        for (int answer : answers) {
            count[answer]++;
        }
        int res = 0;
        for (int i = 0; i < 1000; i++) {
            res += (count[i] / (i + 1)) * (i + 1) + (count[i] % (i + 1) == 0 ? 0 : 1) * (i + 1);
        }
        return res;
    }
};
