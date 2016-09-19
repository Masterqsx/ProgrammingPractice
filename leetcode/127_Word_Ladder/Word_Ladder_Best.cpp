class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        if (wordList.size() == 2) return 0;
        unordered_set<string> search({beginWord}), rest({endWord}), next;
        int size = beginWord.size(), dis = 2;
        while (!search.empty()){
            for (string str:search) wordList.erase(str);
            for (string str:search){
                for (int i=0;i<size;i++){
                    char temp = str[i];
                    for (str[i]='a';str[i]<='z';str[i]++){
                        unordered_set<string>::iterator it = wordList.find(str);
                        if (it != wordList.end()){
                            if (rest.find(*it) != rest.end()) return dis;
                            next.insert(*it);
                        }
                    }
                    str[i] = temp;
                }
            }
            dis++;
            search.swap(next);
            next.clear();
            if (search.size() > rest.size()) search.swap(rest);
        }
        return 0;
    }
};