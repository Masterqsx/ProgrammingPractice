class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (plusOne_helper(digits, 0) > 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
    int plusOne_helper(vector<int>& digits, int i){
        if (i == digits.size()) return 1;
        int count = plusOne_helper(digits, i+1) + digits[i];
        digits[i] = count % 10;
        return count / 10;
    }
};