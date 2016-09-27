class LRUCache{
public:
    int sz;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()){
            pair<int, int> temp= *(it->second);
            order.erase(it->second);
            order.push_front(temp);
            it->second = order.begin();
            return temp.second;
        }
        else return -1;
    }
    
    void set(int key, int value) {
        pair<int, int> temp(key, value);
        order.push_front(temp);
        auto it = cache.find(key);
        if (it != cache.end()){
            order.erase(it->second);
            it->second = order.begin();
        }
        else {
            cache[key] = order.begin();
            if (cache.size() > sz){
                int old_key = order.back().first;
                cache.erase(old_key);
                order.pop_back();
            }
        }
    }
};
