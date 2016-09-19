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
    vector<string> paths;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return vector<string>();
        string s(to_string(root->val));
        if (root->left == NULL && root->right == NULL) return vector<string>({s});
        dfs(root->left, s);
        dfs(root->right, s);
        return paths;
    }
    void dfs(TreeNode* root, string path){
        if (root == NULL) return;
        path += "->";
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};
