#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int treeDP(vector<int> &tree, unordered_set<int> &leaves, vector<int> &val, int n){
  int T[20][2] = {{0}}, maxsum = 0;
  unordered_set<int> next;
  while (leaves.size() > 1){
    for (int j : leaves){
      T[j][1] += val[j];
      int i = tree[j];
      next.insert(i); 
      T[i][0] += max(T[j][0], T[j][1]);
      T[i][1] += T[j][0];
    }
    leaves.swap(next);
    next.clear();
  }
  T[*leaves.begin()][1] += val[*leaves.begin()];
  maxsum = max(T[*leaves.begin()][0], T[*leaves.begin()][1]);
  return maxsum;
}
