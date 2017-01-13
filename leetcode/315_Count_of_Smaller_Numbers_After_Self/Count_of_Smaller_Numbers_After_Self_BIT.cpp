class Solution {
public:
    vector<int> tree;
    int sz;
    void update(int index, int val){
        while (index < sz){
            tree[index] += val;
            index += (index & (-index));
        }
    }
    int getSum(int index){
        int res = 0;
        while (index > 0){
            res += tree[index];
            index = (index & (index-1));
        }
        return res;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() < 1) return vector<int>();
        tree = vector<int>(nums.size()+1, 0);
        sz = nums.size()+1;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> check;
        for (int i=0;i<sz-1;i++) check[temp[i]] = i;
        vector<int> res;
        auto it = nums.rbegin();
        while (it != nums.rend()){
            res.push_back(getSum(check[*it]));
            update(check[*it]+1, 1);
            it++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
