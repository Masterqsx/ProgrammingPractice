/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> sta;
    BSTIterator(TreeNode *root) {
        while(root!=NULL){
            sta.push(root);
            root=root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(sta.empty())
            return false;
        return true;
    }
    
    /** @return the next smallest number */
    int next() {
        int temp=0;
        if(hasNext()){
            temp=sta.top()->val;
            TreeNode* suc=sta.top()->right;
            sta.pop();
            while(suc!=NULL){
                sta.push(suc);
                suc=suc->left;
            }
        }
        return temp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */