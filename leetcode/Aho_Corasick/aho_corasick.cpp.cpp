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

class AC {
public:
    class node {
    public:
        char c;
        int num;
        bool flag;//flag is used to mark is there any substring match
        node* pre;
        node* fail;
        unordered_map<char, node*> next;
        node(): num(-1), pre(NULL), fail(NULL), flag(false){}
        node(char _c): c(_c), num(-1), pre(NULL), fail(NULL), flag(false){}
    };
    node* root;
    vector<string> dict;
    AC() {root = new node();}
    AC(const vector<string>& _dict) {
        root = new node('\0');
        for (int i = 0;i < _dict.size();i++) insert(_dict[i], root, i);
        dict = _dict;
        queue<node*> ne;
        ne.push(root);
        faillink(ne);
    }
    vector<string> search(string str) {
        vector<string> res;
        int i = 0;
        node* cur = root;
        while (i < str.size()) {
            if (!cur->next.empty() && cur->next.count(str[i]) == 1) {//if there is a match in the next character
                node* temp = cur->next[str[i]];
                while (temp != root && temp->flag) {//while its substring has a match, ouput all the words that its substring.
                    if (temp->num >= 0)
                        res.push_back(dict[temp->num]);
                    temp = temp->fail;
                }
                cur = cur->next[str[i]];
                i++;
            }
            else if (cur == root) i++;
            else cur = cur->fail;
        }
        return res;
    }
    void faillink(queue<node*>& ne) {
        while (!ne.empty()) {
            node* cur = ne.front();
            ne.pop();
            node* temp = cur->pre;
            for (auto pa : cur->next) ne.push(pa.second);
            while (temp != NULL) {
                if (temp->fail->next.count(cur->c) == 1 && temp->fail->next[cur->c] != cur) {
                    cur->fail = temp->fail->next[cur->c];//go though father's fail link
                    if (temp->fail->next[cur->c]->flag) cur->flag = true;//if its faillink path contain the end of some words, mark true
                    break;
                }
                if (temp == temp->fail) break;//reach the root
                temp = temp->fail;
            }
            if (cur->fail == NULL) cur->fail = root;
        }
    }
    void insert(string word, node* cur, int index) {
        if (word.empty()) {
            cur->num = index;
            cur->flag = true;
        }
        else {
            if (cur->next.count(word[0]) == 0) {
                cur->next[word[0]] = new node(word[0]);
                cur->next[word[0]]->pre = cur;
            }
            insert(word.substr(1), cur->next[word[0]], index);
        }
    }
    
};
int main()
{
    AC t;
    vector<string> words({"he", "she", "hers", "his", "ssshers", "e", "dream"});
    t = AC(words);
    vector<string> res = t.search("ssshers");
    for (string st : res) cout<<st<<endl;
    return 0;
}
