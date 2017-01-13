class TrieNode {
public:
    int num;
    char c;
    unordered_map<char, TrieNode*> next;
    // Initialize your data structure here.
    TrieNode() {
        num = 0;
    }
    TrieNode(char _c) : c(_c), num(0) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert_r(string word, TrieNode* cur) {
        if (word.empty()) cur->num++;
        else {
            if (cur->next.count(word[0]) == 0) cur->next[word[0]] = new TrieNode(word[0]);
            insert_r(word.substr(1), cur->next[word[0]]);
        }
    }
    void insert(string word) {
        if (word.empty()) return;
        insert_r(word, root);
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        return search_r(word, root);
    }
    bool search_r(string word, TrieNode* cur) {
        if (word.empty() && cur->num > 0) return true;
        if (!word.empty() && cur->next.count(word[0]) == 1) return search_r(word.substr(1), cur->next[word[0]]);
        return false;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return startsWith_r(prefix, root);
    }
    bool startsWith_r(string word, TrieNode* cur) {
        if (word.empty() && cur != root) return true;
        if (!word.empty() && cur->next.count(word[0]) == 1) return startsWith_r(word.substr(1), cur->next[word[0]]);
        return false;
    }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
