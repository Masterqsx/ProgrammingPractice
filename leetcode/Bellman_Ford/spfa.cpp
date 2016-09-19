#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <deque>

using namespace std;

void spfa(unordered_map<int, unordered_map<int, double> > &graph, int n){
  unordered_map<int, int> path;
  unordered_map<int, double> dis({{0, 0}});
  unordered_map<int, int> co;
  unordered_set<int> visiting;
  deque<int> que({0});
  while (!que.empty()){
    int cur = que.front();
    que.pop_front();
    visiting.erase(cur);
    for (auto it : graph[cur]){
      if (dis.count(it.first) == 0 || dis[cur] + it.second < dis[it.first]){
        path[it.first] = cur;
        dis[it.first] = dis[cur] + it.second;
        co[it.first] = co.count(it.first) == 0 ? 1 : co[it.first]+1;
        if (co[it.first] == n){
          cout<<"Contain negative loop"<<endl;
          return;
        }
        if (visiting.count(it.first) == 0){
          if (dis[it.first] < dis[que[0]]) que.push_front(it.first);
          else que.push_back(it.first);
          visiting.insert(it.first);
        }
      }
    }
  }
  
  for (auto it : path)
    cout <<it.second<<" -> "<<it.first<<endl;
  cout <<"================="<<endl;
  for (auto it : dis)
    cout <<it.first<<" : "<<it.second<<endl;
}
