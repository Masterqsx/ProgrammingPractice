#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
using namespace std;
bool valid(vector<int> nums, int n){
  for(int i=0;i<n;i++){
    if( (i+nums[i])==(n+nums[n])||(n-i)==(nums[n]-nums[i]) )
      return false;
  }
  return true;
}

void recursive(vector<vector<int> >& result, vector<int> nums, int n){
  if(n>=nums.size()-1){
    if(valid(nums,n))//Do not miss this part of check
      result.push_back(nums);
    return;
  }
  for(int i=n;i<nums.size();i++){
    swap(nums[i],nums[n]);//
    if(!valid(nums, n)){
 //     swap(nums[i],nums[n]); This belong to another method
      continue;
    }
    recursive(result,nums,n+1);
//    swap(nums[i],nums[n]);
  }
}

int main(){
  ofstream file,file.open("result.txt");
  vector<vector<int> >result;
  int contruct[]={0,1,2,3,4,5,6,7};
  vector<int> nums(contruct,contruct+sizeof(contruct)/sizeof(int));
  recursive(result,nums,0);
  for(int j=0;j<result.size();j++){
    for(int i=0;i<nums.size();i++){
      file<<result[j][i]<<" ";
    }
    file<<endl;
  }
  cout<<result.size()<<endl;
  file.close();
}
