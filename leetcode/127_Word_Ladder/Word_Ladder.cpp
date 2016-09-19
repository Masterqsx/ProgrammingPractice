class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (wordList.empty()) return 0;
        if (wordList.size() == 2 && wordList.find(beginWord) != wordList.end() && wordList.find(endWord) != wordList.end())
            return 0;
        unordered_set<string> search({beginWord});
        unordered_set<string> next;
        int size = beginWord.size(), dis = 2;
        wordList.insert(endWord);
        while (!search.empty()){
            for (string str:search) wordList.erase(str);
            for (string str:search){
                for (int i=0;i<size;i++){
                    char temp = str[i];
                    for (str[i]='a';str[i]<='z';str[i]++){
                        unordered_set<string>::iterator it = wordList.find(str);
                        if (it != wordList.end()){
                            if (*it == endWord) return dis;
                            next.insert(*it);
                        }
                    }
                    str[i] = temp;
                }
            }
            dis++;
            search.swap(next);
            next.clear();
        }
        return 0;
    }
};