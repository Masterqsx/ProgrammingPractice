#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void cycle_detect_directed(unordered_map<int, unordered_map<int, double>> &graph, int n){
  unordered_set<int> white, grey, black;
  unordered_map<int, int> path;
  vector<int> sta;
  int cycle_end = 0;
  for (int i=0;i<n;i++) white.insert(i);
  while (!white.empty() || !grey.empty()){
    if (grey.empty()){
      int cur = *white.begin();
      white.erase(cur);
      grey.insert(cur);
      sta.push_back(cur);
      path[cur] = -1;
    }
    else{
      int cur = sta[sta.size()-1];
      auto it = graph[cur].begin();
      while (it != graph[cur].end()){
        if (it->first != path[cur] && grey.count(it->first) == 1){//the core difference between the undirected and directed
          cycle_end = cur;
          cout<<"detect cycle"<<endl;
          while (cur != -1){
            cout<<cur<<" <- ";
            cur = path[cur];
          }
          return;
        }
        if (it->first != path[cur] && black.count(it->first) == 0){//the core difference between the undirected and directed
          white.erase(it->first);
          grey.insert(it->first);
          sta.push_back(it->first);
          path[it->first] = cur;
          break;
        }
        it++;
      }
      if (it == graph[cur].end()){
        grey.erase(cur);
        sta.pop_back();
        black.insert(cur);
      }
    }
  }
  
}
