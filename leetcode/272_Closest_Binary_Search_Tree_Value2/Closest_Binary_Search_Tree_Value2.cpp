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
    class cmp {
    public:
        bool operator() (const double& lhs, const double& rhs) const{
            return abs(lhs) > abs(rhs);
        }
    };
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        multiset<double, cmp> pq;//Could have same difference
        preorder(root, target, k , pq);
        vector<int> res;
        for (double v : pq) res.push_back(target-v);
        return res;
    }
    void preorder(TreeNode* root, double target, int k, multiset<double, cmp>& pq) {
        if (root == NULL) return;
        if (pq.size() == k && abs(target - root->val) < abs(*pq.begin())) {
            pq.erase(pq.begin());
            pq.insert(target-root->val);
        }
        else if (pq.size() < k) {
            pq.insert(target-root->val);
        }
        preorder(root->left, target, k , pq);//should not simple go left or right
        preorder(root->right, target, k , pq);
    }
};
