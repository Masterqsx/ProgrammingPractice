#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void scc_traverse(int p, int cur, vector<int>& order, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& graph){
  visited.insert(cur);
  for (int node : graph[cur]){
    if (node != p && visited.count(node) == 0){
      scc_traverse(cur, node, order, visited, graph);
    }
  }
  order.push_back(cur);
}

void reverse(unordered_map<int, unordered_set<int>>& graph, unordered_map<int, unordered_set<int>>& rev_graph){
  for (auto pa : graph){
    for (int node : pa.second){
      rev_graph[node].insert(pa.first);
    }
  }
}
void scc(int v, unordered_map<int, unordered_set<int>>& graph){
  unordered_set<int> visited;
  vector<int> order;
  for (int i=0;i<v;i++){
    if (visited.count(i) == 0)
      scc_traverse(i, i, order, visited, graph);
  }
  for (int node : order) cout<<node<<" ";
  cout<<endl;
  visited.clear();
  unordered_map<int, unordered_set<int>> rev_graph;
  reverse(graph, rev_graph);
  for(auto it=order.rbegin();it!=order.rend();it++){
    if (visited.count(*it) == 0){
      vector<int> res;
      scc_traverse(*it, *it, res, visited, rev_graph);
      for (int node : res) cout<<node<<" ";
      cout<<endl;
    }
  }
}

int main(){
  unordered_map<int, unordered_set<int>> graph;
  graph[0] = unordered_set<int>({1});
  graph[1] = unordered_set<int>({2, 3});
  graph[2] = unordered_set<int>({0});
  graph[3] = unordered_set<int>({4});
  graph[4] = unordered_set<int>({5});
  graph[5] = unordered_set<int>({3});
  graph[6] = unordered_set<int>({5, 7});
  graph[7] = unordered_set<int>({8});
  graph[8] = unordered_set<int>({9});
  graph[9] = unordered_set<int>({6, 10});
  graph[10] = unordered_set<int>();
  scc(11, graph);
}
