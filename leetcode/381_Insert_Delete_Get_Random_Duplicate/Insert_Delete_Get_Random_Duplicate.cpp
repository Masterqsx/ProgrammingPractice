class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> index_search;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag;
        if (index_search.count(val) == 1) flag = false;
        else flag = true;
        index_search[val].insert(nums.size());
        nums.push_back(val);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (index_search[val].empty()) return false;
        int index = *index_search[val].begin();
        if (val == nums.back()) {
            index_search[val].erase(nums.size()-1);
            nums.pop_back();
        }
        else {
            swap(nums[index], nums.back());
            index_search[nums[index]].erase(nums.size()-1);
            index_search[nums[index]].insert(index);
            index_search[val].erase(index);
            nums.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (nums.size() > 0) return nums[rand()%nums.size()];
        else return 0;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
