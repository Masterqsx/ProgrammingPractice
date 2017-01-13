class Solution {
public:
    class node {
    public:
        int num;
        unordered_map<int, node*> next;
        node(): num(-1){}
        node(int _n): num(_n){}
    };
    node* root;
    void extend(int num, node* cur, int i) {
        if (i < 0) return;
        int n = (num & (1 << i)) > 0 ? 1 : 0;
        if (cur->next.count(n) == 0) cur->next[n] = new node(n);
        extend(num, cur->next[n], i-1);
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new node();
        for (int n : nums) extend(n, root, 31);
        int res = 0, ma = 0, m = 0;
        node *cur = root;
        for (int n : nums) {
            cur = root;
            res = 0;
            for (int i = 31;i >= 0;i--) {
                int bit = (n & (1 << i)) > 0 ? 1 : 0;
                res = res << 1;
                if (cur->next.count(1-bit) == 1) {
                    res++;
                    cur = cur->next[1-bit];
                }
                else cur = cur->next[bit];
            }
            ma = max(ma, res);
        }
        return ma;
    }
};
