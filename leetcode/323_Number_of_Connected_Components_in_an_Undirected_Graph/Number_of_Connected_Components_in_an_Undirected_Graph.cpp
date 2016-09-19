class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (edges.empty()) return n;
        int res = 0;
        unordered_map<int, unordered_set<int>> graph;
        for (auto pa : edges){
            graph[pa.first].insert(pa.second);
            graph[pa.second].insert(pa.first);
        }
        unordered_set<int> visited;
        for (int i=0;i<n;i++){
            if (visited.count(i) == 0){
                dfs(visited, i, graph);
                res++;
            }
        }
        return res;
    }
    void dfs(unordered_set<int>& visited, int cur, unordered_map<int, unordered_set<int>>& graph){
        visited.insert(cur);
        for (int node : graph[cur]){
            if (visited.count(node) == 0){
                dfs(visited, node, graph);
            }
        }
    }
};
