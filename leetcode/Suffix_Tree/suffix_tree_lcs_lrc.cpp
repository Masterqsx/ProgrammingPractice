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
        pair<int, int> range;
        node* link;
        unordered_set<int> num;
        unordered_map<char, node*> next;
        node(): link(NULL) {range = {-1, -1};}
        node(int l): link(NULL) {range = {l, -1};}
        node(int l, int r): link(NULL) {range = {l, r};}
    };
    node* aN;
    node* root;
    string str;
    int aE = -1, aL = 0, remain = 0, end = 0;
    
    suffixTrie(string _str, int x_sz): str(_str) {
        root = aN = new node();
        str += "$";
        for (int i=0;i<str.size();i++) {
            if (i <= x_sz) extend(i, 0);
            if (i > x_sz) extend(i, 1);
        }
    }
    void lcs_r(node* cur, string& c_res, string& m_res) {
        if (cur->next.size() < 2 || cur->num.size() < 2) return;
        int back = 0;
        if (cur != root) {
            if (c_res.size() + len(cur) > m_res.size()) m_res = c_res + str.substr(cur->range.first, len(cur));
            back = (int)c_res.size();
            c_res += str.substr(cur->range.first, len(cur));
        }
        for(auto pa : cur->next) lcs_r(pa.second, c_res, m_res);
        c_res.erase(back);
    }
    
    void lrs_r(node* cur, string& c_res, string& m_res) {
        if (cur->next.size() < 2) return;
        int back = 0;
        if (cur != root) {
            if (c_res.size() + len(cur) > m_res.size()) m_res = c_res + str.substr(cur->range.first, len(cur));
            back = (int)c_res.size();
            c_res += str.substr(cur->range.first, len(cur));
        }
        for(auto pa : cur->next) lrs_r(pa.second, c_res, m_res);
        c_res.erase(back);
    }
    
    bool isSubstr_r(string st, node* cur) {
        if (cur == root) {
            if (cur->next.count(st[0]) == 1) return isSubstr_r(st, cur->next[st[0]]);
            else return false;
        }
        int i = 0, j = cur->range.first;
        while (i < st.size() && i < len(cur) && st[i] == str[i+j]) i++;
        if (i == st.size()) return true;
        else if (i >= len(cur) && i+j >= end) return false;
        else if (i >= len(cur)) {
            if (cur->next.count(st[i]) == 1) return isSubstr_r(st.substr(i), cur->next[st[i]]);
            else return false;
        }
        else return false;
    }
    
    int len(node* cur) {
        if (cur == root) return 0;
        if (cur->range.second == -1) return end - cur->range.first + 1;
        else return cur->range.second - cur->range.first + 1;
    }
    bool pass(node* cur) {
        if (aL >= len(cur)) {
            aL -= len(cur);
            aE += len(cur);
            aN = cur;
            return true;
        }
        else return false;
    }
    
    void extend(int pos, int flag) {
        remain++;
        end = pos;
        node* late = NULL;
        while (remain > 0) {
            aN->num.insert(flag); //label
            if (aL == 0) aE = pos;
            if (aN->next.count(str[aE]) == 0) {
                aN->next[str[aE]] = new node(pos);
                aN->next[str[aE]]->num.insert(flag);
                if (late != NULL) {
                    late->link = aN;
                    late = NULL;
                }
            }
            else {
                node* ne = aN->next[str[aE]];
                if (pass(ne)) continue;
                if (str[ne->range.first + aL] == str[pos]) {
                    aL++;
                    if (late != NULL) {
                        late->link = aN;
                        late = NULL;
                    }
                    break;
                }
                else {
                    node* new_inter = new node(ne->range.first, ne->range.first + aL - 1);
                    node* new_branch = new node(pos);
                    new_branch->num.insert(flag);
                    new_inter->num = ne->num;
                    new_inter->num.insert(flag);
                    new_inter->next[str[ne->range.first + aL]] = ne;
                    new_inter->next[str[pos]] = new_branch;
                    aN->next[str[aE]] = new_inter;
                    ne->range.first = ne->range.first + aL;
                    if (late != NULL) late->link = new_inter;
                    late = new_inter;
                }
            }
            remain--;
            if (aN == root && aL > 0) {
                aL--;
                aE = pos - remain + 1;
            }
            else if (aN != root) aN = aN->link == NULL?root:aN->link;
        }
    }
    
};
int main()
{
    string str, line;
    str = "GeeksforGeeks#GeeksQuiz";
    suffixTrie t = suffixTrie(str, 13);
    cout<<t.isSubstr_r("xa", t.root)<<endl;
    string c_res, m_res;
    t.lcs_r(t.root, c_res, m_res);
    cout<<m_res<<endl;
    return 0;
}
