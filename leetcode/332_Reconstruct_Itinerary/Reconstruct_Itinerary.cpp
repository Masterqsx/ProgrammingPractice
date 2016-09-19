class Solution {
public:
    class cmp{
    public:
        bool operator() (const string& lhs, const string& rhs) const{
            return lhs.compare(rhs) < 0;
        }
    };
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if (tickets.empty()) return vector<string>();
        unordered_map<string, multiset<string, cmp>> graph;
        for (auto pa : tickets){
            graph[pa.first].insert(pa.second);
        }
        vector<string> res, st;
        string cur, next;
        st.push_back("JFK");
        while (!st.empty()){
            cur = st.back();
            if (graph.count(cur) == 1 && graph[cur].size() > 0){
                next = *(graph[cur].begin());
                graph[cur].erase(graph[cur].find(next));
                st.push_back(next);
            }
            else{
                res.push_back(cur);
                st.pop_back();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
