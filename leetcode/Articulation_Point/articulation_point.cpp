#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
int n = 1;
void find_articulation(int p, int cur, vector<int>& index, vector<int>& low, unordered_map<int, unordered_set<int>>& graph){
  int childcount = 0;
  low[cur] = index[cur] = n++;
  for (int node : graph[cur]){
    if (index[node] < 0){
      childcount++;
      find_articulation(cur, node, index, low, graph);
      if (low[node] >= index[cur] && p != cur) cout<<"find articulation point "<<cur<<endl;//the comparision shoud between the child low and current index
      low[cur] = min(low[cur], low[node]);
    }
    else if (node != p){
      low[cur] = min(low[cur], index[node]);
    }
  }
  if (p == cur && childcount > 1) cout<<"find articulation point "<<cur<<endl;
}
int main(){
  unordered_map<int, unordered_set<int>> graph;
  graph[0] = unordered_set<int>({1, 3});
  graph[1] = unordered_set<int>({0, 2});
  graph[2] = unordered_set<int>({1, 6, 3});
  graph[3] = unordered_set<int>({0, 4, 2, 5});
  graph[4] = unordered_set<int>({3, 5});
  graph[5] = unordered_set<int>({3, 4});
  graph[6] = unordered_set<int>({2});
  vector<int> index = vector<int>(7, -1);
  vector<int> low = vector<int>(7, 7);
  find_articulation(0, 0, index, low, graph);
  return 0;
}
  
