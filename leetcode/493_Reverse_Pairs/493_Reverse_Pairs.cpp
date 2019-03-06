class Solution {
public:
    class Node {
        public:
            int start;
            int end;
            int val;
            Node* left;
            Node* right;
            Node(int s, int e, int v): start(s), end(e), val(v) {}
    };
    Node* build(int start, int end) {
        Node* cur = new Node(start, end, 0);
        if (start != end) {
            int mid = start + (end - start) / 2;
            cur->left = build(start, mid);
            cur->right = build(mid + 1, end);
        }
        return cur;
    }
    void update(Node* n, int index) {
        if (n->start == n->end && n->start == index) n->val += 1;
        else {
            int mid = n->start + (n->end - n->start) / 2;
            if (mid >= index) update(n->left, index);
            else update(n->right, index);
            n->val = n->left->val + n->right->val;
        }
    }
    int query(Node* n, int start, int end) {
        if (n->start <= end && start <= n->end && start <= end) {
            if (n->start >= start && n->end <= end) return n->val;
            else return query(n->left, start, end) + query(n->right, start, end);
        } else return 0;
    }
    
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        Node* root = build(0, nums.size() - 1);
        vector<int> numsSorted = vector<int>(nums.begin(), nums.end());
        sort(numsSorted.begin(), numsSorted.end());
        int res = 0;
        for (int j = 0; j < nums.size(); j++) {
            res += query(root, upper_bound(numsSorted.begin(), numsSorted.end(), 2LL * nums[j]) - numsSorted.begin(), nums.size() - 1);
            update(root, lower_bound(numsSorted.begin(), numsSorted.end(), nums[j]) - numsSorted.begin());
        }
        return res;
    }
};
