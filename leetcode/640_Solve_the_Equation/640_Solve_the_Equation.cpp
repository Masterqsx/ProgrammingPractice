class Solution {
public:
    void calculate(int& a, int& b, string eq) {
        int flag = 1, cur = 0;
        for (int i = 0; i < eq.length(); i++) {
            if (eq[i] == '-' || eq[i] == '+') {
                b += flag * cur;
                flag = eq[i] == '-' ? -1 : 1;
                cur = 0;
            } else if (eq[i] == 'x') {
                if (!(i > 0 && eq[i - 1] == '0')) a += flag * max(1, cur);
                cur = 0;
            } else {
                cur = cur * 10 + eq[i] - '0';
            }
        }
        b += flag * cur;
    }
    string solveEquation(string equation) {
        int al = 0, bl = 0, ar = 0, br = 0;
        string l = equation.substr(0, equation.find('='));
        string r = equation.substr(equation.find('=') + 1);
        calculate(al, bl, l);
        calculate(ar, br, r);
        if (al == ar) {
            if (bl == br) return "Infinite solutions";
            else return "No solution";
        }
        else return "x=" + to_string((bl - br) / (ar - al));
    }
};
