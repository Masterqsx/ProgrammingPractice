class Solution {
public:
    int calculate(string s) {
        vector<int> nb;
        vector<char> op;
        for (int i = 0;i < s.size();i++){
            if (s[i] >= '0' && s[i] <= '9'){
                nb.push_back(atoi(s.c_str()+i));
                while (s[i] >= '0' && s[i] <= '9') i++;
                i--;
            }
            else if (s[i] == '-' || s[i] == '+'){
                temp(nb, op);
                op.push_back(s[i]);
            }
            else if (s[i] == '(')
                op.push_back(s[i]);
            else if (s[i] == ')'){
                temp(nb, op);
                op.pop_back();
            }
        }
        temp(nb, op);
        return nb.front();
    }
    void temp(vector<int>& nb, vector<char>& op){
        if (!op.empty() && op.back() != '('){
            int b = nb.back();
            nb.pop_back();
            int a = nb.back();
            nb.pop_back();
            nb.push_back(cal(a, b, op.back()));
            op.pop_back();
        }
    }
    int cal(int a, int b, char c){
        return c == '+'?a+b:a-b;
    }
};