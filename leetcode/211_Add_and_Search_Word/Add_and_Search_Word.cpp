class WordDictionary {
public:
    class node {
    public:
        int num;
        char c;
        unordered_map<char, node*> next;
        node(): num(0) {};
        node(char _c): c(_c), num(0) {};
    };
    node* root;
    WordDictionary() {root = new node();}
    void insert(string& word, node* cur, int i) {
        if (i == word.size() && cur != root) cur->num++;
        else {
            if (cur->next.count(word[i]) == 0) cur->next[word[i]] = new node(word[i]);
            insert(word, cur->next[word[i]], i+1);
        }
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int i = 0;
        node* cur = root;
        while (i < word.size()) {
            if (cur->next.count(word[i]) == 0) cur->next[word[i]] = new node(word[i]);
            cur = cur->next[word[i]];
            i++;
        }
        if (cur != root) cur->num++;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search_r(string word, node* cur) {
        if (word.empty() && cur->num > 0) return true;
        else if (!word.empty() && (word[0] == '.' || cur->next.count(word[0]) == 1)) {
            if (word[0] != '.') return search_r(word.substr(1), cur->next[word[0]]);
            else {
                for (auto pa : cur->next) {
                    if (search_r(word.substr(1), pa.second)) return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return search_r(word, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
