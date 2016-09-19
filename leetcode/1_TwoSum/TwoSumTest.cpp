class Solution {
  public:
    static bool compare(pair<int,int>a,pair<int,int>b){
      return a.first<b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> result;
      vector<pair<int,int> > temp;
      for(int i=0;i<nums.size();i++){
        temp.push_back(pair<int,int>(nums[i],i));
      }

      sort(temp.begin(),temp.end(),Solution::compare);
      for(int i=0;i<nums.size();i++){
        int lo = i+1;
        int hi = nums.size()-1;
        while(lo<=hi){
          int mid = lo+(hi-lo)/2;
          if(temp[mid].first==(target-temp[i].first)){
            result.push_back(temp[i].second);
            result.push_back(temp[mid].second);
            return result;

          }
          else if(temp[mid].first>(target-temp[i].first)){
            hi=mid-1;
          }
          else if(temp[mid].first<(target-temp[i].first)){
            lo=mid+1;
          }
        }
      }
    }
};
