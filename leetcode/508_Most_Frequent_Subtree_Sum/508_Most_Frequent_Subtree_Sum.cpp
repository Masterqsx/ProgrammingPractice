/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int, int>& res, int& maxFreq) {
        if (root == NULL) return 0;
        int l = dfs(root->left, res, maxFreq);
        int r = dfs(root->right, res, maxFreq);
        int cur = l + r + root->val;
        if (res.find(cur) != res.end()) {
            res[cur] += 1;
        } else res[cur] = 1;
        maxFreq = max(maxFreq, res[cur]);
        return cur;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> res;
        int maxFreq = 0;
        dfs(root, res, maxFreq);
        vector<int> r;
        for (auto it = res.begin(); it != res.end(); it++) {
            if (it->second == maxFreq) r.push_back(it->first);
        }
        return r;
    }
};
