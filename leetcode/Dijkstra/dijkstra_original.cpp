#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

void dijkstra(unordered_map<int, unordered_map<int, double> > &graph){
  unordered_map<int, int> path({{0, -1}});
  unordered_map<int, double> dis, cur_nodes({{0, 0}});//Initialization
  auto cmp = [](pair<const int, double> &lhs, pair<const int, double> &rhs){ return lhs.second<rhs.second;};

  while (!cur_nodes.empty()){
    auto it = min_element(cur_nodes.begin(), cur_nodes.end(), cmp); //find minimum in the queue
    cout<<path[it->first]<<" -> "<<it->first<<endl; //print out fixed shortest path
    dis[it->first] = it->second; //push into distance map
    for (auto i : graph[it->first]){ //push or update the vertices the vectex with minimal distance connecting to
      if (dis.count(i.first) == 0 && (cur_nodes.count(i.first) == 0 || cur_nodes[i.first] > i.second+it->second)){
        cur_nodes[i.first] = i.second+it->second;
        path[i.first] = it->first;
      }
    }
    cur_nodes.erase(it->first);
  }
  cout<<"=========="<<endl;
  for (auto i : dis){
    cout<<i.first<<" : "<<i.second<<endl;
  }
}
