class Solution {
public:
    vector<string> dic;
    unordered_map<char, unordered_set<char>> order;
    string alienOrder(vector<string>& words) {
        if (words.size() < 2) return string();
        dic = words;
        vector<int> index;
        for (int i=0;i<dic.size();i++){
            index.push_back(i);
            for (char c : dic[i]){
                order[c] = unordered_set<char>();
            }
        }
        recursion(0, index);
        string res;
        if (!t_sort(res, order)) return string();
        return res;
    }
    bool t_sort(string& res, unordered_map<char, unordered_set<char>>& graph){
        unordered_set<char> white, grey, black;
        for (auto pa : graph) white.insert(pa.first);
        vector<char> sta;
        while (!white.empty() || !grey.empty()){
            if (grey.empty()){
                sta.push_back(*white.begin());
                grey.insert(sta.back());
                white.erase(sta.back());
            }
            else{
                char cur = sta.back();
                auto it = graph[cur].begin();
                while (it != graph[cur].end()){
                    if (grey.count(*it) == 1)
                        return false;
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
                    res = cur + res;
                }
            }
        }
        return true;
    }
    void recursion(int level, vector<int> index){
        if (index.size() < 2) return;
        unordered_map<char, vector<int>> check;
        vector<char> sequence;
        for (int n : index){
            if (level >= dic[n].size()) continue;
            if (check.count(dic[n][level]) == 0)
                sequence.push_back(dic[n][level]);
            check[dic[n][level]].push_back(n);
        }
        
        for (int i=0;i<(int)sequence.size()-1;i++)
            order[sequence[i]].insert(sequence[i+1]);
        for (auto pa : check)
            recursion(level+1, pa.second);
    }
};w