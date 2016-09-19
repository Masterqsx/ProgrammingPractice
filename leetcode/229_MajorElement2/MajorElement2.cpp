class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<2) return vector<int>(nums);
        vector<int> re;
        int count0=0,count1=0,p0=0,p1=0;
        for(int i=0;i<nums.size();i++){
            if((count0>0)&&(p0!=nums[i])&&(count1>0)&&(p1!=nums[i])){
                count0--;
                count1--;
            }
            else if((count0>0)&&(p0==nums[i])){
                count0++;
            }
            else if((count1>0)&&(p1==nums[i])){
                count1++;
            }
            else if(count0==0){
                p0=nums[i];
                count0++;
            }
            else{
                p1=nums[i];
                count1++;
            }
            
        }
        int count0_c=0,count1_c=0;
        for(int i=0;i<nums.size();i++){
            if((count0>0)&&(nums[i]==p0))
                count0_c++;
            else if((count1>0)&&(nums[i]==p1))
                count1_c++;
        }
        if(count0_c>nums.size()/3) re.push_back(p0);
        if(count1_c>nums.size()/3) re.push_back(p1);
        return re;
    }
};