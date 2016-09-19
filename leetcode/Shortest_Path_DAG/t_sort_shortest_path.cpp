#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;
void t_sort(vector<int>& res, int cur, unordered_set<int>& visited, unordered_set<int>& visiting, unordered_map<int, unordered_map<int, int>>& graph){
  if (graph.empty()) return;
  visiting.insert(cur);
  for (auto node : graph[cur]){
   if (visiting.count(node.first) == 1) return;
   else if (visited.count(node.first) == 0){
    t_sort(res, node.first, visited, visiting, graph);
   }
  }
  res.push_back(cur);
  visited.insert(cur);
  visiting.erase(cur);
}

void shortest_path(int v,unordered_map<int, unordered_map<int, int>>& graph){
  vector<int> res;
  unordered_set<int> visited;
  unordered_set<int> visiting;
  for(int i=0;i<v;i++){
    if (visited.count(i) == 0)
      t_sort(res, i, visited, visiting, graph);
  }
  vector<int> dis = vector<int>(v, numeric_limits<int>::max());
  dis[0] = 0;
  for (int i=v-1;i>=0;i--){
    for (auto pa : graph[res[i]]){
      if (dis[res[i]] != numeric_limits<int>::max() && dis[pa.first] > dis[res[i]] + pa.second)
        dis[pa.first] = dis[res[i]] + pa.second;
    }
  }
  for (int i=0;i<v;i++) cout<<dis[i]<<endl;
  //for (auto it=res.rbegin();it!=res.rend();it++) cout<<*it<<endl;
}

int main(){
  unordered_map<int, unordered_map<int, int>> graph;
  graph[0] = unordered_map<int, int>({{1,6}, {2, 2}});
  graph[1] = unordered_map<int, int>({{5, 1}, {4, -1}});
  graph[2] = unordered_map<int, int>({{4, 4}, {5, 2}, {1, 7}});
  graph[3] = unordered_map<int, int>({{0, 5}, {2, 3}});
  graph[4] = unordered_map<int, int>({{5, -2}});
  graph[5] = unordered_map<int, int>();
  shortest_path(6, graph);
}
