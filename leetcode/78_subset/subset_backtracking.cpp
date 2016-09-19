class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int> > result;
      vector<int> temp;
      result.push_back(temp);
      sort(nums.begin(),nums.end());
      recursive(nums, result, 0, temp);
      return result;
    }
    void recursive(vector<int> nums, vector<vector<int> >& result, int n, vector<int>& temp){
      for(int i=n;i<nums.size();i++){
        temp.push_back(nums[i]);
        result.push_back(temp);
        recursive(nums, result, i+1, temp);
        temp.pop_back();
      }
    }
};
