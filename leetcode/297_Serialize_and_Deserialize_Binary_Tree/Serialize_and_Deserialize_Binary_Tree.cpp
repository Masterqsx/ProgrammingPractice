/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, string& res) {
        if (root == NULL) {
            res += "#,";
            return;
        }
        res += to_string(root->val);
        res += ",";
        helper(root->left, res);
        helper(root->right, res);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dehelper(ss);
    }
    TreeNode* dehelper(stringstream& ss){
        if (ss.peek() == ',') ss.get(); //skip delim
        if (ss.peek() == '#') {
            ss.get();
            return NULL;
        }
        int v = 0;
        ss >> v;
        TreeNode* re = new TreeNode(v);
        re->left = dehelper(ss);
        re->right = dehelper(ss);
        return re;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
