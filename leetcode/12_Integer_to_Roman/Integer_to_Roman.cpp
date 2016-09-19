class Solution {
public:
    string intToRoman(int num) {
        char match[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int search[] = {1000, 500, 100, 50, 10, 5, 1};
        int remain = num, i = 0;
        string res;
        while (remain > 0){
            if (search[i] > remain) i++;
            else if (search[i] == remain){
                res += match[i];
                return res;
            }
            else{
                if (i != 0 && (search[i-1] - search[(i+1)/2*2]) <= remain){
                    res += match[(i+1)/2*2];
                    res += match[i-1];
                    remain -= (search[i-1] - search[(i+1)/2*2]);
                }
                else {
                    res += match[i];
                    remain -= search[i];
                }
                i = 0;
            }
        }
        return res;
    }
};