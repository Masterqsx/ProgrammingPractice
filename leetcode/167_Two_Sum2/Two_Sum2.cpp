class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int lo = 0, hi = numbers.size()-1;
        while (lo < hi){
            if (numbers[lo] + numbers[hi] == target){
                res = vector<int>({lo+1, hi+1});
                return res;
            }
            else if (numbers[lo] + numbers[hi] > target) hi--;
            else lo++;
        }
        return res;
    }
};
