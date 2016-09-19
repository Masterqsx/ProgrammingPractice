class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        int i = 0;
        for (auto pa : equations){
            graph[pa.first][pa.second] = values[i];
            graph[pa.second][pa.first] = 1 / values[i];
            i++;
        }
        vector<double> res;
        for (auto pa : queries){
            if (graph.count(pa.first) == 0 || graph.count(pa.second) == 0) res.push_back(-1);
            else {
                if (!dfs(graph, res, 1, pa.first, pa.first, pa.second)) res.push_back(-1);
            }
        }
        return res;
    }
    bool dfs(unordered_map<string, unordered_map<string, double>>& graph, vector<double>& res, double nb, string cur, string p, string tar){
        if (cur == tar){
            res.push_back(nb);
            return true;
        }
        else if (graph[cur].size() <= 1 && cur != p) return false;
        for (auto node : graph[cur]){
            if (node.first != p){
                if (dfs(graph, res, nb * node.second, node.first, cur, tar)) return true;
            }
        }
        return false;
    }
};
