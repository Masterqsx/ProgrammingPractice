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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        if(root==NULL) return re;
        TreeNode* temp=new TreeNode(0);
        temp->left=root;
        TreeNode* cur=temp;
        while(cur!=NULL){
            if(cur->left==NULL){
                cur=cur->right;
            }
            else{
                TreeNode* pre=cur->left;
                while((pre->right!=NULL)&&(pre->right!=cur)) pre=pre->right;
                if(pre->right==NULL){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    pre->right=NULL;
                    unsigned int size=re.size();
                    pre=cur->left;
                    while(pre!=NULL){
                        re.push_back(pre->val);
                        pre=pre->right;
                    }
                    reverse(re.begin()+size,re.end());
                    cur=cur->right;
                }
            }
            
        }
        delete temp;
        return re;
    }
};