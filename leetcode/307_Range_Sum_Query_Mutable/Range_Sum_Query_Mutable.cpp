class NumArray {
public:
    class node{
    public:
        int lo;
        int hi;
        int val;
        node(int _lo, int _hi):lo(_lo), hi(_hi), val(0){}
    };
    vector<node> tree;
    int sz;
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        sz = ceil(log(nums.size())/log(2));
        sz = 2*pow(2,sz)-1;
        tree = vector<node>(sz, node(0,0));
        construct(nums, 0, nums.size()-1, 0);
    }
    int construct(vector<int>& nums, int lo, int hi, int index){
        if (index >= sz) return 0;
        tree[index].lo = lo;
        tree[index].hi = hi;
        tree[index].val = nums[lo];
        if (lo == hi) return nums[lo];
        int l = construct(nums, lo, (hi+lo)/2, 2*index+1);
        int r = construct(nums, (hi+lo)/2+1, hi, 2*index+2);
        tree[index].val = l+r;
        return tree[index].val;
    }
    void update(int i, int val) {
        update_r(i, val, 0);
    }
    int update_r(int i, int val, int index){
        if (i == tree[index].lo && i == tree[index].hi) return tree[index].val = val;
        else if (i < tree[index].lo || i > tree[index].hi) return tree[index].val;
        else {
            int l = update_r(i, val, 2*index+1);
            int r = update_r(i, val, 2*index+2);
            tree[index].val = l+r;
            return l+r;
        }
    }
    int sumRange(int i, int j) {
        return sumRange_r(i, j, 0);
    }
    int sumRange_r(int i, int j, int index){
        if (tree[index].lo > j || tree[index].hi < i) return 0;
        if (tree[index].lo >= i && tree[index].hi <= j) return tree[index].val;
        int l = sumRange_r(i, j, 2*index+1);
        int r = sumRange_r(i, j, 2*index+2);
        return l+r;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
