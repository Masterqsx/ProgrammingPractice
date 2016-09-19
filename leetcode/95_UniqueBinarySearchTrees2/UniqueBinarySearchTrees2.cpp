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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> re;
        if(n<1) return re;
        return buildTree(1,n);
    }
    vector<TreeNode*> buildTree(int b,int e){
        vector<TreeNode*> re;
        if(b>e) re.push_back(NULL);
        else if(b==e) re.push_back(new TreeNode(b));
        else{
            for(int i=b;i<=e;i++){
                vector<TreeNode*> l=buildTree(b,i-1);
                vector<TreeNode*> r=buildTree(i+1,e);
                for(int j=0;j<l.size();j++){
                    for(int k=0;k<r.size();k++){
                        TreeNode* h=new TreeNode(i);
                        h->left=l[j];
                        h->right=r[k];
                        re.push_back(h);
                    }
                }
            }
        }
        return re;
    }
};