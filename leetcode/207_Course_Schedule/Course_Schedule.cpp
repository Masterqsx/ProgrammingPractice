class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto co : prerequisites)
            graph[co.first].insert(co.second);
        unordered_set<int> white, grey, black;
        for (int i=0;i<numCourses;i++) white.insert(i);
        vector<int> stac;
        while (!white.empty() || !grey.empty()){
            if (grey.empty()){
                stac.push_back(*white.begin());
                grey.insert(*white.begin());
                white.erase(stac.back());
            }
            else{
                int cur = stac.back();
                auto it = graph[cur].begin();
                while (it != graph[cur].end()){
                    if (grey.count(*it) == 1)
                        return false;
                    else if (black.count(*it) == 0){
                        grey.insert(*it);
                        stac.push_back(*it);
                        break;
                    }
                    it++;
                }
                if (it == graph[cur].end()){
                    black.insert(cur);
                    grey.erase(cur);
                    stac.pop_back();
                }
            }
        }
        return true;
    }
};