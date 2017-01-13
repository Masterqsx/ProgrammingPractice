class RandomizedSet {
public:
    unordered_map<int, int> index_search;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index_search.count(val) == 1) return false;
        else {
            index_search[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index_search.count(val) == 0) return false;
        else {
            int index = index_search[val];
            swap(nums[index], nums.back());
            index_search[nums[index]] = index;
            index_search.erase(val);
            nums.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
