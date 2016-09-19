class Solution {
public:
    unordered_map<string, unordered_set<string>> adj;
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        if (wordList.size() == 2) return res;
        adj[beginWord] = unordered_set<string>();
        vector<string> search({beginWord}), next;
        int dis = 2, size = beginWord.size(), isFind = 0;
        while (!search.empty() && !isFind){
            for (string str:search) wordList.erase(str);
            for (string str:search){
                for (int i=0;i<size;i++){
                    char temp = str[i];
                    string str_t = str;
                    for (str[i] = 'a';str[i] <= 'z';str[i]++){
                        auto it = wordList.find(str);
                        if (it != wordList.end()){
                            if (*it == endWord) isFind = 1;
                            if (adj.count(str_t) == 0) adj[str_t] = unordered_set<string>({str});
                            else adj[str_t].insert(str);
                            next.push_back(str);
                        }
                    }
                    str[i] = temp;
                }
            }
            if (!next.empty() && !isFind) dis++;
            search.swap(next);
            next.clear();
        }
        path.push_back(beginWord);
        if (isFind) generatePath(beginWord, endWord, dis);
        return res;
    }
    void generatePath(string &str, string &endWord, int dis){
        if (dis <= 1){
            res.push_back(path);
            return ;
        }
        for (string str_n:adj[str]){
            path.push_back(str_n);
            if (dis > 2 || (dis == 2 && str_n == endWord)) generatePath(str_n, endWord, dis-1);
            path.pop_back();
        }
    }
};