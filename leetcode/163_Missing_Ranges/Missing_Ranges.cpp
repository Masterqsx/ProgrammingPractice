class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (lower > upper) return vector<string>();
        if (nums.empty()) return vector<string>({generateRange(lower, upper)});
        vector<string> res;
        if (nums[0] > lower) res.push_back(generateRange(lower, nums[0]-1));
        for (int i=0;i<nums.size()-1;i++){
            if (nums[i] < nums[i+1]-1) res.push_back(generateRange(nums[i]+1, nums[i+1]-1));
        }
        if (nums.back() < upper) res.push_back(generateRange(nums.back()+1, upper));
        return res;
    }
    string generateRange(int lo, int hi){
        if (lo > hi) return string();
        if (lo == hi) return string(to_string(lo));
        return string(to_string(lo)+"->"+to_string(hi));
    }
};
