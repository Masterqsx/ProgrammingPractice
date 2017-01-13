class Solution {
public:
    string parseTernary(string expression) {
        vector<char> sta;
        for (int i = expression.size()-1;i >= 0;i--) {
            if (expression[i] >= '0' && expression[i] <= '9' || expression[i] == 'F' || expression[i] == 'T') {
                sta.push_back(expression[i]);
            }
            else if (expression[i] == '?') {
                char t;
                if (expression[i-1] == 'T') t = sta[sta.size()-1];
                else t = sta[sta.size()-2];
                sta.pop_back();
                sta.pop_back();
                sta.push_back(t);
                i--;
            }
        }
        return string(1, sta[0]);
    }
};
