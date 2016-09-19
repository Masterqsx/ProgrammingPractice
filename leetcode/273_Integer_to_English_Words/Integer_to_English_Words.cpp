class Solution {
public:
    unordered_map<int, string> kw;
    vector<int> check;
    string numberToWords(int num) {
        kw = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};
        check = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20};
        string res;
        if (num <= 0) return string("Zero");
        recursive(res, num, 0);
        if (res.back() == ' ') res.pop_back();
        return res;
    }
    void recursive(string& res, int num, int i){
        if (num > 0){
            for (;i<check.size();i++){
                if (num >= check[i]) break;
            }
            if (i == check.size()){
                res += kw[num];
                res += " ";
            }
            else {
                if (check[i] > 90) recursive(res, num / check[i], i);
                res += kw[check[i]];
                res += " ";
                recursive(res, num % check[i], i);
            }
        }
    }
};