class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string res(S);
        int tmp = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            tmp += shifts[i] % 26;
            tmp = tmp % 26;
            if (tmp > 'z' - S[i]) res[i] = 'a' + tmp - 1 - 'z' + S[i];
            else res[i] += tmp;
        }
        return res;
    }
};
