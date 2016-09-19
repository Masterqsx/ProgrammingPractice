class Solution {//with O(nlogn) time and O(n) space complexity
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> sum=accumu(nums);
        int minlength=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int lo=i,hi=nums.size()-1;
            while(lo<hi){
                int mid=lo+(hi-lo)/2;
                if(sum[mid]-sum[i]+nums[i]==s){
                    minlength=min(minlength,mid-i+1);
                    break;
                }
                else if(sum[mid]-sum[i]+nums[i]>s) hi=mid;
                else lo=mid+1;
            }
            minlength=(sum[hi]-sum[i]+nums[i]>=s)?min(minlength,hi-i+1):minlength;
        }
        return minlength==INT_MAX?0:minlength;
    }
    vector<int> accumu(vector<int> nums){
        vector<int> re;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            re.push_back(sum);
        }
        return re;
    }
    
};