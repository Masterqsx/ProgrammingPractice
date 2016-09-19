class Solution {
public:
    vector<int> countBits(int num) {
        if (num < 0) return vector<int>();
        if (num == 0) return vector<int>({0});
        int old = 1, next = 1;
        vector<int> re({0});
        for (int i=1;i<=num;i++){
            if (i == next){
                re.push_back(1);
                old = next;
                next *= 2;
            }
            else re.push_back(re[i-old]+re[old]);//the core part, we can use the previous number of hot bits
        }
        return re;
    }
};