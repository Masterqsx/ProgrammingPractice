class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        stringstream ss(abbr);
        int i = 0, count = 0;
        char c;
        while (!ss.eof() && i < word.size()){
            if (ss.peek() > '0' && ss.peek() <= '9'){
                ss >> count;
                while (count > 0) {
                    i++;
                    count--;
                    if (i > word.size()) return false;
                }
            }
            else {
                ss >> c;
                if (word[i] != c) return false;
                i++;
            }
        }
        if (ss.peek()==-1 && i >= word.size()) return true;
        else return false;
    }
};
