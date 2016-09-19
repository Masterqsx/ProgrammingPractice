class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) return 1;
        vector<queue<long> > que;
        que.push_back(queue<long>({2}));
        que.push_back(queue<long>({3}));
        que.push_back(queue<long>({5}));
        long mi = 0, nb = 1, prime[3] = {2, 3, 5};
        for (int i = 1;i < n;i++){
            mi = 0, nb = que[0].front();
            for (int j = 1;j < 3;j++){
                if (que[j].front() < nb){
                    mi = j;
                    nb = que[j].front();
                }
            }
            que[mi].pop();
            for (int j = mi;j < 3;j++)
                que[j].push(nb * prime[j]);
        }
        return nb;
    }
};