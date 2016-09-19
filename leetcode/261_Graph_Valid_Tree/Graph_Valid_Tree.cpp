class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n < 2) return true;
        if (edges.empty()) return false;
        unordered_set<int> visited;
        unordered_map<int, unordered_set<int>> graph;
        for (auto pa : edges){
            graph[pa.first].insert(pa.second);
            graph[pa.second].insert(pa.first);
        }
        return dfs(visited, graph.begin()->first, graph.begin()->first, graph) && visited.size() == n;
    }
    bool dfs(unordered_set<int>& visited, int cur, int p, unordered_map<int, unordered_set<int>>& graph){
        visited.insert(cur);
        for (int node : graph[cur]){
            if (visited.count(node) == 1){
                if (node != p) return false;
            }
            else if (!dfs(visited, node, cur, graph)) return false;
        }
        return true;
    }
};
