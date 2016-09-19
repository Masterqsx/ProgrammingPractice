class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        unsigned long long sz = word.size();
        unsigned long long itera_len = 1<<sz;
        vector<string> res;
        for (unsigned long long i=0;i<itera_len;i++){
            unsigned long long count = 0;
            string cob;
            for (unsigned long long j=0;j<sz;j++){
                if (count > 0 && (i & (1<<j)) == 0){
                    cob = to_string(count) + cob;
                    count = 0;
                    j--;
                }
                else if (count == 0 && (i & (1<<j)) == 0){
                    cob = word[sz - 1 - j] + cob;
                }
                else if ((i & (1<<j)) != 0){
                    count++;
                }
            }
            if (count > 0) cob = to_string(count) + cob;
            res.push_back(cob);
        }
        return res;
    }
};