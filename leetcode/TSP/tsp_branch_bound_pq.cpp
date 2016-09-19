#include <iostream>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

class state{
  public:
    unsigned long long pattern;
    int end;
    double len;
    state(unsigned long long p, int e, double l) : pattern(p), end(e), len(l){}
};

void tsp(unordered_map<int, unordered_map<int, double>> &graph, int n){
  auto cmp = [](state *lhs, state *rhs){return lhs->len < rhs->len;};
  priority_queue<state *, vector<state *>, decltype(cmp)> state_queue(cmp);
  unsigned long long cob_len = pow(2, n-1);
  double min_cycle = DBL_MAX;
  for (auto it : graph[0]){
    state *cur = new state(1<<(it.first-1), it.first, it.second);
    state_queue.push(cur);
  }
  while (!state_queue.empty()){
    state *cur = state_queue.top();
    state_queue.pop();
    if (cur->pattern == cob_len - 1 && graph[cur->end].count(0) == 1){
      min_cycle = min(min_cycle, graph[cur->end][0] + cur->len);
      delete cur;
      continue;
    }
    for (auto it : graph[cur->end]){
      if (it.first == 0 || (cur->pattern & (1<<(it.first-1))) > 0) continue;
      state *next = new state(cur->pattern | (1<<(it.first-1)), it.first, it.second+cur->len);
      state_queue.push(next);
    }
    delete cur;
  }

  cout<<min_cycle<<endl;
}

