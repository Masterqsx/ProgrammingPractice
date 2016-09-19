#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class solution{
  public:
    void recursion(int n, vector<vector<int> >& res, vector<int> nums){
      if(n >= (nums.size()-1)){
        res.push_back(nums);
        return;
      }
      for(int i=n;i<nums.size();i++){
        if(i!=n && nums[i]==nums[n]){
          continue;
        }
        swap(nums[i],nums[n]);
        recursion(n+1, res, nums);
      }
    }
    void recursion_c(int n, vector<vector<int> >& res, vector<int>& nums){
      if(n >= (nums.size()-1)){
        res.push_back(nums);
        return;
      }
      int last=10000000;
      for(int i=n;i<nums.size();i++){
        if(i!=n && (nums[i]==nums[n]||nums[i]==last)){
          continue;
        }
        last=nums[i];
        swap(nums[i],nums[n]);
        recursion(n+1, res, nums);
        swap(nums[i],nums[n]);
      }
    }

    vector<vector<int> >  permutation(vector<int> &nums){
      vector<vector<int> > res;
      sort(nums.begin(),nums.end());
      recursion(0, res, nums);
      return res;
    }
    vector<vector<int> >  permutation_c(vector<int> &nums){
      vector<vector<int> > res;
      sort(nums.begin(),nums.end());
      recursion_c(0, res, nums);
      return res;
    }

};

int main(){
  solution a;
  vector<int> nums;
  vector<int> nums_c;
  ofstream file1;
  ofstream file2;
  file1.open("test.txt");
  file2.open("test_c.txt");
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
// nums.push_back(2);
//  nums.push_back(3);
  nums_c=nums;
  vector<vector<int> > res=a.permutation(nums);
  vector<vector<int> > res_c=a.permutation_c(nums_c);
  cout<<res.size()<<endl;
  cout<<res_c.size()<<endl;
  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      file1<<res[i][j];
    }
    file1<<endl;
  }
  for(int i=0;i<res_c.size();i++){
    for(int j=0;j<res_c[i].size();j++){
      file2<<res_c[i][j];
    }
    file2<<endl;
  }
  file2.close();
  file1.close();
  return 0;
}
