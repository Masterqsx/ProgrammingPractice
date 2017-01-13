// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    unordered_set<int> visited;
    int findCelebrity(int n) {
        bool flag = true;
        int cur = 0;
        while (flag) {
            flag = false;
            visited.insert(cur);
            for (int i=0;i<n;i++){
                if (visited.count(i) == 0 && i != cur && knows(cur, i)) {
                    flag = true;
                    cur = i;
                }
            }
        }
        for (int i=0;i<n;i++){
            if (cur != i && (!knows(i, cur) || knows(cur, i))) return -1;
        }
        return cur;
    }
};
