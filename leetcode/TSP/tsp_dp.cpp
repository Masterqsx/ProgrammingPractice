#include <iostream>
#include <unordered_map>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

void tsp(unordered_map<int, unordered_map<int, double>> &graph, int n){
  unsigned long long cob_len = pow(2, n-1);
  double dp[n][cob_len];
  for (int i=1;i<n;i++){
    if (graph[0].count(i) == 0) dp[i][0] = DBL_MAX;
    else dp[i][0] = graph[0][i];
  }

  for (unsigned long long cob = 1;cob < cob_len-1; cob++){
    for (int i=0;i<n-1;i++){
      if ((cob & 1<<i) >= 1) continue;
      double minimum = DBL_MAX;
      for (int j=0;j<n-1;j++){
        if ((cob & 1<<j) >= 1){
          if (graph[j+1].count(i+1) == 0) continue;
          minimum = min(minimum, graph[j+1][i+1]+dp[j+1][cob & (~(1<<j))]);
        }
      }
      dp[i+1][cob] = minimum;
      cout<<i+1<<" "<<cob<<" "<<minimum<<endl;
    }
  }
  
  double min_cycle = DBL_MAX;
  for (int i = 1;i<n;i++){
    if (graph[i].count(0) == 0) continue;
    min_cycle = min(min_cycle, graph[i][0]+dp[i][(cob_len-1) & (~(1<<(i-1)))]);
  }
  cout << min_cycle << endl;
}
