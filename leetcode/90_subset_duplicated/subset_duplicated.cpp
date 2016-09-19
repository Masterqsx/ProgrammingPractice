class Solution {
  public:
    void recursive(vector<vector<int> >& result, vector<int> nums, vector<int>& temp, int n){
      int last=10000;
      for(int i=n;i<nums.size();i++){
        if(nums[i]==last) //major difference from situation without duplicated number 
          continue;
        last=nums[i];
        temp.push_back(nums[i]);
        result.push_back(temp);
        recursive(result, nums, temp, i+1);
        temp.pop_back();

      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int> > result;
      sort(nums.begin(),nums.end());
      vector<int> temp;
      result.push_back(temp);
      recursive(result,nums,temp,0);
      return result;
    }
};
