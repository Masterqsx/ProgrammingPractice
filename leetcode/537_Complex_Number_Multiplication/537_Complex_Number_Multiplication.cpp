class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1 = stoi(a.substr(0, a.find('+', 1)));
        int a2 = stoi(b.substr(0, b.find('+', 1)));
        int b1 = stoi(a.substr(a.find('+', 1) + 1, a.find('i') - a.find('+', 1) + 1));
        int b2 = stoi(b.substr(b.find('+', 1) + 1, b.find('i') - b.find('+', 1) + 1));
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
