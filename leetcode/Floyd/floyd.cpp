#include <iostream>
#include <cfloat>
#include <unordered_map>

using namespace std;

void floyd(unordered_map<int, unordered_map<int, double> > &graph, int n){
  int path[n][n];
  double dis[n][n];
  
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i == j){
        path[i][j] = i;
        dis[i][j] = 0;
        continue;
      }
      auto it = graph[i].find(j);
      if (it != graph[i].end()){
        path[i][j] = i;
        dis[i][j] = it->second;
      }
      else{
        path[i][j] = -1;
        dis[i][j] = DBL_MAX;
      }
    }
  }
  for (int k=0;k<n;k++){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        if (dis[i][k] != DBL_MAX && dis[k][j] != DBL_MAX && dis[i][k]+dis[k][j]
            < dis[i][j]){
          dis[i][j] = dis[i][k] + dis[k][j];
          path[i][j] = k;
        }
      }
    }
  }
  
  double undirected_min = DBL_MAX, directed_min = DBL_MAX;

  for (int k=0;k<n;k++){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        if (i != j)
          undirected_min = min(undirected_min, dis[j][i]+dis[i][k]+dis[k][j]);
      }
    }
  }

  for (auto src_map : graph){
    for (auto dest_pair : src_map.second){
      directed_min = min(directed_min, dest_pair.second + dis[dest_pair.first][src_map.first]);
    }
  }

  cout <<"If the graph is undirected, the min cycle is "<<undirected_min<<endl;
  cout <<"if the graph is directed, the min cycle is "<<directed_min<<endl;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout<<i<<" and "<<j<<" pass "<<path[i][j]<<" distance "<<dis[i][j]<<endl;
    }
  }
}
