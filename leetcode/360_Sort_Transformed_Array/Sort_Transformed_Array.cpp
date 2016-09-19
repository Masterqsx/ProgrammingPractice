class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) return vector<int>();
        vector<int> res;
        if (a == 0) {
            if (b >= 0) {
                for (int n : nums) res.push_back(b*n+c);
            }
            else {
                for (int i = nums.size()-1;i>=0;i--) res.push_back(b*nums[i]+c);
            }
        }
        else {
            double mid = -((double)b/(double)a/2); //Pay attention to the type casting
            if (a < 0){
                int lo = 0, hi = nums.size()-1;
                while (lo <= hi){
                    if (abs(mid - nums[lo]) >= abs(mid - nums[hi])){
                        res.push_back(a*nums[lo]*nums[lo]+b*nums[lo]+c);
                        lo++;
                    }
                    else{
                        res.push_back(a*nums[hi]*nums[hi]+b*nums[hi]+c);
                        hi--;
                    }
                }
            }
            else{
                int hi = 0;
                for (;hi < nums.size() && nums[hi] < mid;hi++) {}
                int lo = hi - 1;
                while (lo >=0 || hi < nums.size()){
                    if (lo < 0 || abs(mid - nums[lo]) >= abs(mid - nums[hi]) && hi < nums.size()){ //pay attention to condition
                        res.push_back(a*nums[hi]*nums[hi]+b*nums[hi]+c);
                        hi++;
                    }
                    else if(hi >= nums.size() || abs(mid - nums[lo]) < abs(mid - nums[hi])){
                        res.push_back(a*nums[lo]*nums[lo]+b*nums[lo]+c);
                        lo--;
                    }
                }
            }
        }
        return res;
    }
};