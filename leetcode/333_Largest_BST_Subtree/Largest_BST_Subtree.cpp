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
    class sta {
    public:
        int mi;
        int ma;
        int sz;
        bool is;
        sta(){}
        sta(int imi, int ima, int isz, bool iis): mi(imi), ma(ima), sz(isz), is(iis){}
    };
    int max_st = 0;
    int largestBSTSubtree(TreeNode* root) {
        postorder(root);
        return max_st;
    }
    sta postorder(TreeNode* root) {
        if (root == NULL) return sta(0, 0, 0, true);
        sta l = postorder(root->left);
        sta r = postorder(root->right);
        sta re;
        if (l.is && r.is && (l.sz > 0 && l.ma < root->val || l.sz == 0) && (r.sz > 0 && r.mi > root->val || r.sz == 0)) {
            re.is = true;
            re.sz = l.sz + r.sz + 1;
            re.mi = l.sz > 0?l.mi:root->val;
            re.ma = r.sz > 0?r.ma:root->val;
            max_st = max(max_st, re.sz);
        }
        else re.is = false;
        return re;
    }
};
