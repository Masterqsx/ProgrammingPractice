class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res = vector<string>();
        int state = 0;
        string buf = string();
        for (string str : source) {
            for (int i = 0; i < str.length(); i++) {
                if (state == 0 && str[i] == '"') state = 1;
                else if (state == 1 && str[i] == '"') state = 0;
                else if (state == 0 && i < str.length() - 1 && str[i] == '/' && str[i + 1] == '*') {
                    state = 2;
                    i += 2;
                }
                else if (state == 2 && i > 0 && str[i - 1] == '*' && str[i] == '/') state = 4;
                else if (state == 0 && i < str.length() - 1 && str[i] == '/' && str[i + 1] == '/') state = 3;
                else if (state == 3 && i == str.length() - 1) state = 4;
                
                if (state == 2 || state == 3 || state == 4) {
                    if (state == 4) state = 0;
                    continue;
                }
                buf += str[i];
            }
            if (buf.length() > 0 && state != 2) {
                res.push_back(buf);
                buf = string();
            }
        }
        return res;
    }
};
