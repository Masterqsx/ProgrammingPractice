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
    string dfs(TreeNode* root, unordered_map<string, int>& m, unordered_map<string, TreeNode*>& se) {
        if (root == NULL) return "#";
        string h = to_string(root->val) + "," + dfs(root->left, m, se) + "," + dfs(root->right, m, se);
        if (m.find(h) != m.end()) {
            m[h]++;
            se[h] = root;
        }
        else m[h] = 1;
        return h;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        unordered_map<string, TreeNode*> se;
        dfs(root, m, se);
        for (auto it = se.begin(); it != se.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
