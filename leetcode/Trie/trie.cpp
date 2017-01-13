#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <regex>
#include <string>
#include <cassert>
#include <list>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
class trie {
public:
    class node {
    public:
        string str;
        int num;
        unordered_map<char, node*> next;
        node () : num(0) {}
        node (string _str) : str(_str), num(1) {}
    };
    node* root;
    trie () { root = new node();}
    void display(node* cur, vector<string>& st, string cur_str) {
        if (cur->num > 0) st.push_back(cur_str);
        if (!cur->next.empty()) {
            for (auto pa : cur->next) {
                string ne_str = cur_str + pa.second->str;
                display(pa.second, st, ne_str);
            }
        }
    }
    void insert(string word) {
        if (word.empty()) return;
        if (root->next.count(word[0]) == 0) {
            root->next[word[0]] = new node (word);
        }
        else {
            insert_helper(word, root->next[word[0]]);
        }
    }
    void insert_helper(string word, node* cur) {
        int i = 0;
        while (i < cur->str.size() && i < word.size()) {
            if (word[i] != cur->str[i]) break;
            i++;
        }
        if (i == cur->str.size() && i == word.size()) cur->num++;
        else if (i == cur->str.size()) {
            if (cur->next.count(word[i]) == 0) cur->next[word[i]] = new node(word.substr(i));
            else insert_helper(word.substr(i), cur->next[word[i]]);
        }
        else {
            node* child = new node(cur->str.substr(i));
            child->next.swap(cur->next);
            swap(child->num, cur->num);
            cur->next[cur->str[i]] = child;
            cur->str.erase(i);
            if (i != word.size()) {
                cur->num = 0;
                node* child2 = new node(word.substr(i));
                cur->next[word[i]] = child2;
            }
        }
    }
};

class simpletrie {
public:
    class node {
    public:
        char c;
        int num;
        unordered_map<char, node*> next;
        node () : num(0) {}
        node (char _c) : c(_c), num(0) {}
    };
    node* root;
    simpletrie() {
        root = new node();
    }
    bool search(string word, node* cur) {
        if (word.empty()) return true;
        if (cur->next.count(word[0]) == 0) return false;
        else return search(word.substr(1), cur->next[word[0]]);
    }
    void display(node* cur, vector<pair<string, int>>& res, string& cur_str) {
        if (cur->num > 0) res.push_back({cur_str, cur->num});
        for (auto pa : cur->next) {
            cur_str += pa.first;
            display(pa.second, res, cur_str);
            cur_str.pop_back();
        }
    }
    void insert_helper(string word, node* cur) {
        if (word.empty()) cur->num++;
        else {
            if (cur->next.count(word[0]) == 0) cur->next[word[0]] = new node(word[0]);
            insert_helper(word.substr(1), cur->next[word[0]]);
        }
    }
    void insert(string word){
        if (word.empty()) return;
        if (root->next.count(word[0]) == 0) root->next[word[0]] = new node(word[0]);
        insert_helper(word.substr(1), root->next[word[0]]);
    }
};

int main()
{
    simpletrie t = simpletrie();
    int i = 0;
    while (i < 4) {
        string str;
        cin >> str;
        t.insert(str);
        i++;
    }
    vector<pair<string,int>> strs;
    string cur_str;
    t.display(t.root, strs, cur_str);
    for (auto st : strs) cout<<st.first<<" "<<st.second<<endl;
    cout<<t.search("sde", t.root)<<endl;
    return 0;
}
