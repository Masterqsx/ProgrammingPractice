class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (edges.empty() || n <= 0) return vector<int>({0});
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> degree;
        
        for (auto pa : edges){
            degree[pa.first]++;
            degree[pa.second]++;
            graph[pa.first].insert(pa.second);
            graph[pa.second].insert(pa.first);
        }
        
        while (degree.size() > 2){
            queue<int> leaf;
            for (auto pa : degree){
                if (pa.second == 1) leaf.push(pa.first);
            }
            while (!leaf.empty()){
                degree.erase(leaf.front());
                degree[*graph[leaf.front()].begin()]--;
                graph[*graph[leaf.front()].begin()].erase(leaf.front());
                graph.erase(leaf.front());
                leaf.pop();
            }
        }
        vector<int> res;
        for (auto pa : degree){
            res.push_back(pa.first);
        }
        return res;
    }
    
};
