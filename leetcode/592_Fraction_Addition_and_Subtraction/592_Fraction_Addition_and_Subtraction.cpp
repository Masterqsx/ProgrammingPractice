class Solution {
public: 
    vector<int> parse(string expression) {
        vector<int> res = vector<int>(10, 0);
        int i = 0;
        while(1) {
            int flag = expression[i] == '-' ? -1 : 1;
            if (expression[i] == '-' || expression[i] == '+') i++;
            int nNeg = expression.find('-', i);
            int nPos = expression.find('+', i);
            int end = -1;
            if (nNeg == -1) end = nPos;
            else if (nPos == -1 || nPos > nNeg) end = nNeg;
            else end = nPos;
            string cur;
            if (end == -1) cur = expression.substr(i);
            else cur = expression.substr(i, end - i);
            int nom = stoi(cur.substr(0, cur.find('/')));
            int den = stoi(cur.substr(cur.find('/') + 1));
            res[den - 1] += (flag * nom);
            
            if (end == -1) break;
            else i = end;
        }
        return res;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    string fractionAddition(string expression) {
        vector<int> exp = parse(expression);
        int count = 0;
        for (int i = 0; i < exp.size(); i++) {
            count += 2520 / (i + 1) * exp[i];
        }
        int fraction = abs(count) > 2520 ? gcd(abs(count), 2520) : gcd(2520, abs(count));
        
        if (fraction == 0) return "0/1";
        return to_string(count / fraction) + "/" + to_string(2520 / fraction);
    }
};
