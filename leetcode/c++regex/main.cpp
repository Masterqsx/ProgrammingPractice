#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <regex>
#include <string>
#include <cassert>
#include <list>

using namespace std;
class LRUCache{
public:
    int sz;
    deque<pair<int, int>> order;
    unordered_map<int, deque<pair<int, int>>::iterator> cache;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()){
            pair<int, int> temp= *(it->second);
            order.erase(it->second);
            order.push_front(temp);
            cache[key] = order.begin();
            assert(check() == true);
            return temp.second;
        }
        else return -1;
    }
    
    bool check(){
        for(auto pa : order){
            if (cache.count(pa.first) != 1 || cache[pa.first]->first != pa.first) return false;
        }
        return true;
    }
    void set(int key, int value) {
        pair<int, int> temp(key, value);
        order.push_front(temp);
        auto it = cache.find(key);
        if (it != cache.end()){
            order.erase(it->second);
            cache[key] = order.begin();
            assert(check() == true);
        }
        else {
            cache[key] = order.begin();
            if (cache.size() > sz){
                int old_key = order.back().first;
                cache.erase(old_key);
                order.pop_back();
                assert(check() == true);
            }
        }
    }
};
int main()
{
    ifstream in;
    in.open("/Users/qianshengxin/Desktop/test/test/test.txt");
    string ob;
    getline(in, ob);
    regex pattern("set\\(([0-9]+),([0-9]+)\\)|get\\(([0-9]+)\\)");
    smatch res;
    LRUCache t(105);
    while(regex_search(ob, res, pattern)){
        if (res.str()[0] == 's'){
            t.set(stoi(res.str(1)),stoi(res.str(2)));
        }
        else cout<<t.get(stoi(res.str(3)))<<endl;
        ob = res.suffix();
    }
    return 0;
}
