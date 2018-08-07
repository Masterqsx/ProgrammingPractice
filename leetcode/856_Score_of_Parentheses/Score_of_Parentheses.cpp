class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> intStack = vector<int>();
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') intStack.push_back(0);
            else if (intStack.back() == 0) intStack.back() += 1;
            else {
                int tmp = 0;
                while (!intStack.empty() && intStack.back() != 0) {
                    tmp += intStack.back() * 2;
                    intStack.pop_back();
                }
                intStack.back() += tmp;
            }
        }
        int res = 0;
        while (!intStack.empty()) {
            res += intStack.back();
            intStack.pop_back();
        }
        return res;
    }
};
