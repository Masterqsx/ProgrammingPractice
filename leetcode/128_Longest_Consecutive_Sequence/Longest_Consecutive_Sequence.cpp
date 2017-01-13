class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 1, cur = 0;
        unordered_set<int> check;
        for (int i : nums) check.insert(i);
        for (int i : nums) {
            if (check.count(i) == 0) continue;
            cur = 0;
            queue<int> que({i});
            while (!que.empty()) {
                int n = que.front();
                if (check.count(n) != 0) {
                    check.erase(n);
                    que.push(n - 1);
                    que.push(n + 1);
                    cur++;
                }
                que.pop();
            }
            res = max(res, cur);
        }
        return res;
    }
};
