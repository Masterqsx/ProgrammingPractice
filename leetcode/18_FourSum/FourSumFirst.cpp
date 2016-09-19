class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> re=vector<vector<int>>();
        if(nums.size()<4) return re;
        
        sort(nums.begin(),nums.end());
        if(nums.size()==4){
            if(accumulate(nums.begin(),nums.end(),0)==target){
                re.push_back(nums);
            }
            return re;
        }
        
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                if((i!=0)&&(nums[i]==nums[i-1])) continue;//make sure the number before is unique
                if((j!=i+1)&&(nums[j]==nums[j-1])) continue;
                
                search(re,nums,i,j,j+1,target-nums[i]-nums[j]);
            }
        }
        return re;
    }
    
    void search(vector<vector<int>>& re,vector<int> nums,int i,int j,int k,int target){
        int lo=k;
        int hi=nums.size()-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]>target){
                hi--;
            }
            else if(nums[lo]+nums[hi]<target){
                lo++;
            }
            else{
                if(!((lo!=k)&&(nums[lo]==nums[lo-1])||(hi!=nums.size()-1)&&(nums[hi]==nums[hi+1]))){
                    re.push_back(vector<int>()={nums[i],nums[j],nums[lo],nums[hi]});
                }
                hi--;
                lo++;
            }
        }
    }
    
};