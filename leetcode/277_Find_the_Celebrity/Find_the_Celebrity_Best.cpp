// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0;
        for (int i=0;i<n;i++){
            if (knows(cur, i)) cur = i;
        }
        for (int i=0;i<n;i++){
            if (cur != i && (!knows(i, cur) || knows(cur, i))) return -1;
        }
        return cur;
    }
};
