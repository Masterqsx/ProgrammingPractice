class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        unordered_map<int, set<int>> subset;
        sort(nums.begin(), nums.end());
        int len = 1, index = 0;
        for (int i=nums.size()-1;i>=0;i--){
            subset[i] = set<int>({nums[i]});
            int len_i = 0, index_i = i;
            for (int j=i+1;j<nums.size();j++){
                if (nums[j] % nums[i] == 0 && subset[j].size() > len_i){
                    len_i = subset[j].size();
                    index_i = j;
                }
            }
            subset[i].insert(subset[index_i].begin(),subset[index_i].end());
            if (len < subset[i].size()){
                len = subset[i].size();
                index = i;
            }
        }
        return vector<int>(subset[index].begin(), subset[index].end());
    }
};