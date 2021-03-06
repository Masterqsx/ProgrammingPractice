class NumArray {
public:
    vector<int> nb;
    NumArray(vector<int> &nums) {
        nb.resize(nums.size()+1);
        nb[0] = 0;
        for (int i=0;i<nums.size();i++){
            nb[i+1] = nb[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return nb[j+1] - nb[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
