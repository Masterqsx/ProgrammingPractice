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
        unordered_map<char, node*> next;
        node() {link = NULL; range = pair<int, int>(-1, -1);}
        node(int l) {link = NULL; range = pair<int, int>(l, -1);}
        node(int l, int r) {link = NULL; range = pair<int, int>(l, r);}
    };
    string str;
    node* root;
    int end;
    node* activeNode;
    int activeLength = 0;
    int activeEdge = -1;
    int remainder = 0;
    suffixTrie(string _str): str(_str), end(0){
        activeNode = root = new node();
        construct();
    }
    
    int edgelength(node* cur) {
        if (cur->range.second == -1) return end - cur->range.first + 1;
        else return cur->range.second - cur->range.first + 1;
    }
    
    int walkdown(node* cur) {
        if (activeLength >= edgelength(cur)) {
            activeLength -= edgelength(cur);
            activeNode = cur;
            activeEdge += edgelength(cur);
            return 1;
        }
        return 0;
    }
    
    void construct() {
        str += "$";
        for (int i = 0; i < str.size(); i++) extend(i);
    }
    
    void extend(int pos) {
        remainder++;
        end = pos;
        node* last = NULL;
        while (remainder > 0) {
            if (activeLength == 0) activeEdge = pos;
            if (activeNode->next.count(str[activeEdge]) == 0) {
                activeNode->next[str[activeEdge]] = new node(pos);
                if (last != NULL) {
                    last->link = activeNode;
                    last = NULL;
                }
            }
            else {
                node* ne = activeNode->next[str[activeEdge]];
                if (walkdown(ne)) continue;
                if (str[ne->range.first + activeLength] == str[pos]) {
                    activeLength++;
                    if (last != NULL && activeNode != root) {
                        last->link = activeNode;
                        last = NULL;
                    }
                    break;
                }
                else {
                    node* new_inter = new node(ne->range.first, ne->range.first + activeLength - 1);
                    node* new_branch = new node(pos);
                    new_inter->next[str[ne->range.first + activeLength]] = ne;
                    new_inter->next[str[pos]] = new_branch;
                    activeNode->next[str[ne->range.first]] = new_inter;
                    ne->range.first += activeLength;
                    if (last != NULL) last->link = new_inter;
                    last = new_inter;
                }
            }
            remainder--;
            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = pos - remainder + 1;
            }
            else if (activeNode != root) activeNode = (activeNode->link == NULL ? root : activeNode->link);
        }
    }
    
};
int main()
{
    string str = "mississi";
    suffixTrie t = suffixTrie(str);
    return 0;
}
