class Solution {
public:
    class node {
    public:
        char c;
        int index;
        unordered_map<char, node*> next;
        node() {index = -1;};
        node(char _c) : c(_c), index(-1){}
    };
    node* root;
    unordered_set<int> visiting;
    unordered_set<int> valid_word;
    int h;
    int w;
    void insert(node* cur, string word, int index) {
        if (word.empty()) cur->index = index;
        else {
            if (cur->next.count(word[0]) == 0) cur->next[word[0]] = new node(word[0]);
            insert(cur->next[word[0]], word.substr(1), index);
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty()) return vector<string>();
        root = new node();
        h = board.size();
        w = board[0].size();
        for (int i = 0;i < words.size();i++) {
            if (!words[i].empty()) insert(root, words[i], i);
        }
        vector<string> res;
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                if (root->next.count(board[i][j]) == 1) {
                    visiting.insert(i*w+j);
                    dfs(board, i, j, res, words, root->next[board[i][j]]);
                    visiting.erase(i*w+j);
                }
            }
        }
        return res;
    }
    bool isValid(node* cur, int i, int j, vector<vector<char>>& board) {
        if (visiting.count(i*w+j) == 0 && i >= 0 && i < h && j >= 0 && j < w && cur->next.count(board[i][j]) == 1) return true;
        else return false;
    }
    void dfs(vector<vector<char>>& board, int i, int j, vector<string>& res, vector<string>& words, node* cur) {
        if (cur->index != -1) {
            if (valid_word.count(cur->index) == 0) {
                res.push_back(words[cur->index]);
                valid_word.insert(cur->index);
            }
        }
        if (isValid(cur, i-1, j, board)) {
            visiting.insert((i-1)*w+j);
            dfs(board, i-1, j, res, words, cur->next[board[i-1][j]]);
            visiting.erase((i-1)*w+j);
        }
        if (isValid(cur, i+1, j, board)) {
            visiting.insert((i+1)*w+j);
            dfs(board, i+1, j, res, words, cur->next[board[i+1][j]]);
            visiting.erase((i+1)*w+j);
        }
        if (isValid(cur, i, j-1, board)) {
            visiting.insert(i*w+j-1);
            dfs(board, i, j-1, res, words, cur->next[board[i][j-1]]);
            visiting.erase(i*w+j-1);
        }
        if (isValid(cur, i, j+1, board)) {
            visiting.insert(i*w+j+1);
            dfs(board, i, j+1, res, words, cur->next[board[i][j+1]]);
            visiting.erase(i*w+j+1);
        }
    }
};
