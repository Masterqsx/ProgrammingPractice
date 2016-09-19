#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

class cmp_c {
public:
    bool operator() (const string &lhs, const string &rhs) const{
        return lhs.compare(rhs)<0;
    }
};
int main()
{
    auto cmp_pq = [](int lhs, int rhs){return lhs <= rhs;};
    auto cmp_set = [](string lhs, string rhs){return lhs.compare(rhs)<0;};
    priority_queue<int, vector<int>, decltype(cmp_pq)> pq(cmp_pq,{1,2,3});
    while (!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<" "<<endl;
    
    set<string, decltype(cmp_set)> se({"a","s","c","d","b"},cmp_set);
    for (auto str : se) cout<<str<<endl;
    cout<<" "<<endl;
    
    multiset<string, cmp_c> se1({"a", "c", "s", "c", "d", "b"}, cmp_c());
    for (auto str : se1) cout<<str<<endl;
    cout<<" "<<endl;
    for (auto it = se1.lower_bound("c");it!=se1.end();it++) cout<<*it<<endl;
    cout<<endl;
    
    multiset<string, cmp_c> se2({"a", "c", "s", "c", "d", "b"});
    for (auto str : se2) cout<<str<<endl;
    return 0;
}


