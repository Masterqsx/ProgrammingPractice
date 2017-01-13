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
#include <queue>

using namespace std;

class suffixTrie {
public:
    class node {
    public:
        int num;
        string c;
        unordered_map<char, node*> next;
        node(): num(-1) {}
        node(string _c): num(-1), c(_c) {}
    };
    node* root;
    string str;
    suffixTrie(string _str): str(_str) {
        root = new node();
        for (int i = 0;i < str.size();i++) insert(str.substr(i)+"$", root, i);
        compress(root);
    }
    void insert(string word, node* cur, int index) {
        if (word.empty()) cur->num = index;
        else {
            if (cur->next.count(word[0]) == 0) cur->next[word[0]] = new node(word.substr(0,1));
            insert(word.substr(1), cur->next[word[0]], index);
        }
    }
    void compress(node* cur) {
        if (cur->next.empty()) return;
        for (auto pa : cur->next) compress(pa.second);
        if (cur->next.size() == 1 && cur != root) {
            node* succ = cur->next.begin()->second;
            cur->num = succ->num;
            cur->c += succ->c;
            swap(cur->next, succ->next);
            delete succ;
        }
    }
    string lrs;
    void find_longest(node* cur, string curs) {
        if (cur != root && cur->next.size() < 2) return;
        curs += cur->c;
        for (auto pa : cur->next) find_longest(pa.second, curs);
        if (curs.size() > lrs.size()) lrs = curs;
    }
};
int main()
{
    string str = "  abcpqrabpqpqabc  ";
    suffixTrie t = suffixTrie(str);
    t.find_longest(t.root, string());
    return 0;
}
