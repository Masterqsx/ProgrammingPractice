#include <unordered_map>
#include <iostream>

using namespace std;

void bellman_ford(unordered_map<int, unordered_map<int, double> > &graph, int v){
  unordered_map<int, int> path;
  unordered_map<int, double> dis({{0, 0}});
  bool flag = true;
  int n = 0;
  while (flag && n <= v){
    flag = false;
    for (auto src_map : graph){
      for (auto dest_map : src_map.second){
        auto it = dis.find(src_map.first);
        if (it != dis.end() && (dis.count(dest_map.first) == 0
              || dis[src_map.first] + dest_map.second < dis[dest_map.first])){
          flag = true;
          dis[dest_map.first] = dis[src_map.first] + dest_map.second;
          path[dest_map.first] = src_map.first;
        }
      }
    }
    n++;
  }
  if (n == v){
    cout<<"Contain negative loop"<<endl;
    return;
  }
  for (auto it : path)
    cout <<it.second<<" -> "<<it.first<<endl;
  cout <<"================="<<endl;
  for (auto it : dis)
    cout <<it.first<<" : "<<it.second<<endl;
}
