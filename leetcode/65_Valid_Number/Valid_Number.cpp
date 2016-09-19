class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        bool flag = false;
        for (int i = 0;i < s.size();i++){
            switch (state) {
                case 0 :{
                    if (s[i] == ' ') continue;
                    else if (s[i] == '+' || s[i] == '-') state = 1;
                    else if (s[i] >= '0' && s[i] <= '9'){
                        state = 2;
                        flag = true;
                    }
                    else if (s[i] == '.') state = 3;
                    else state = 7;
                    break;
                }
                case 1 :{
                    if (s[i] >= '0' && s[i] <= '9'){
                        state = 2;
                        flag = true;
                    }
                    else if (s[i] == '.') state = 3;
                    else state = 7;
                    break;
                }
                case 2 :{
                    if (s[i] >= '0' && s[i] <= '9') state = 2;
                    else if (s[i] == '.') state = 3;
                    else if (s[i] == 'e') state = 4;
                    else if (s[i] == ' ') state = 8;
                    else state = 7;
                    break;
                }
                case 3 :{
                    if (s[i] >= '0' && s[i] <= '9'){
                        state = 5;
                        flag = true;
                    }
                    else if (s[i] == ' ') state = 8;
                    else if (s[i] == 'e') state = 4;
                    else state = 7;
                    break;
                }
                case 4 :{
                    if (s[i] >= '0' && s[i] <= '9') state = 6;
                    else if (s[i] == '-' || s[i] == '+') state = 9;
                    else state = 7;
                    break;
                }
                case 5 :{
                    if (s[i] >= '0' && s[i] <= '9') continue;
                    else if (s[i] == 'e') state = 4;
                    else if (s[i] == ' ') state = 8;
                    else state = 7;
                    break;
                }
                case 6 :{
                    if (s[i] >= '0' && s[i] <= '9') continue;
                    else if (s[i] == ' ') state = 8;
                    else state = 7;
                    break;
                }
                case 7 :{
                    return false;
                }
                case 8 :{
                    if (s[i] != ' ') return false;
                    break;
                }
                case 9 :{
                    if (s[i] >= '0' && s[i] <= '9') state = 6;
                    else state = 7;
                }
            }
        }
        if ((state == 2 || state == 6 || state == 5 || state == 8 || state == 3)&& flag) return true;
        else return false;
    }
};