#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void prim(unordered_map<int, unordered_map<int, double> > &graph){
  unordered_map<int, int> path({{0, -1}});
  unordered_map<int, double> cur_nodes({{0, 0}});
  unordered_set<int> fixed;
  auto cmp = [](pair<const int, double> &lhs, pair<const int, double> &rhs){ return lhs.second < rhs.second; }; 

  while (!cur_nodes.empty()){
    auto it = min_element(cur_nodes.begin(), cur_nodes.end(), cmp);
    cout << path[it->first] << " -> " << it->first<<endl;
    fixed.insert(it->first);
    for (auto i : graph[it->first]){
      if (fixed.count(i.first) == 0 && (cur_nodes.count(i.first) == 0 || cur_nodes[i.first] > i.second)){
        path[i.first] = it->first;
        cur_nodes[i.first] = i.second;
      }
    }
    cur_nodes.erase(it);
  }
}
