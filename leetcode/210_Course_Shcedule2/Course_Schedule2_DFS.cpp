class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        for (int i=0;i<numCourses;i++) graph[i] = unordered_set<int>();
        for (auto pa : prerequisites) graph[pa.first].insert(pa.second);
        vector<int> res;
        if (!t_sort(res, graph)) return vector<int>();
        return res;
    }
    bool t_sort(vector<int>& res, unordered_map<int, unordered_set<int>>& graph){
        unordered_set<int> white, grey, black;
        for (auto pa : graph) white.insert(pa.first);
        vector<int> sta;
        while (!white.empty() || !grey.empty()){
            if (grey.empty()){
                sta.push_back(*white.begin());
                white.erase(sta.back());
                grey.insert(sta.back());
            }
            else{
                int cur = sta.back();
                auto it = graph[cur].begin();
                while (it != graph[cur].end()){
                    if (grey.count(*it) == 1) return false;
                    else if (black.count(*it) == 0){
                        grey.insert(*it);
                        sta.push_back(*it);
                        white.erase(*it);
                        break;
                    }
                    it++;
                }
                if (it == graph[cur].end()){
                    black.insert(cur);
                    grey.erase(cur);
                    sta.pop_back();
                    res.push_back(cur);
                }
            }
        }
        return true;
    }
};