class Solution {
public:
    int flag;
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        vector<int> temp;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        flag=nums[0]-1;
        for(int i=0;i<nums.size()-2;i++){
            if((nums[i-1]==nums[i])&&(i>0)) continue; //key part
            for(int j=i+1;j<nums.size()-1;j++){
                if((j!=i+1)&&(nums[j]==nums[j-1])) continue;//key part
                int result=binarysearch(j+1,(0-nums[i]-nums[j]),nums);
                if(result!=flag){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(result);
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
    
    int binarysearch(int begin,int target,vector<int> nums){
        int lo=begin;
        int hi=nums.size()-1;
        int middle=0;
        while(lo<=hi){
            middle=lo+(hi-lo)/2;
            if(nums[middle]<target){
                lo=middle+1;
            }
            else if(nums[middle]>target){
                hi=middle-1;
            }
            else{
                return nums[middle];
            }
        }
        return flag;
    }
};