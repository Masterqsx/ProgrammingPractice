class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int> > result;
      vector<int> temp;
      sort(nums.begin(),nums.end());
      recursive(nums, result, 0, temp);
      return result;
    }
    void recursive(vector<int> nums, vector<vector<int> >& result, int n, vector<int>& temp){
      if(n>=nums.size()){
        result.push_back(temp);
        return;
      }
      temp.push_back(nums[n]);
      recursive(nums, result, n+1, temp);
      temp.pop_back();
      recursive(nums, result, n+1, temp);


    }
};
