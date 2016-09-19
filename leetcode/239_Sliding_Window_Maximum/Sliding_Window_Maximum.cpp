class Solution {
public:
    void mqPush(deque<int>& mq, vector<int>& nums, int i){
        while (!mq.empty() && nums[mq.back()] <= nums[i])
            mq.pop_back();
        mq.push_back(i);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0) return res;
        deque<int> mq;
        int start = 0;
        for (int i=0;i<nums.size();i++){
            if (i < start+k) mqPush(mq, nums, i);
            else{
                res.push_back(nums[mq[0]]);
                if (mq[0] == start) mq.pop_front();
                start++;
                mqPush(mq, nums, i);
            }
        }
        res.push_back(nums[mq[0]]);
        return res;
    }
};