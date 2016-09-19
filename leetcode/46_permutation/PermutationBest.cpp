class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutation;
      PermuteRecursive(permutation,nums,0);
      return permutation;
    }
            
    void PermuteRecursive(vector<vector<int>>& permutation, vector<int>& nums, int n){
      if(n>=(nums.size()-1)){
        permutation.push_back(nums);
        return;
      }
      for(int i=n;i<nums.size();i++){
        swap(nums[i],nums[n]);
        PermuteRecursive(permutation,nums,n+1);
        swap(nums[i],nums[n]);
      }
    }
};
