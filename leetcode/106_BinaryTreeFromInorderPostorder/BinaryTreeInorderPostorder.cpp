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
    int index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if((inorder.size()==0)||(postorder.size()!=inorder.size())) return NULL;
        index=inorder.size()-1;
        return recursive(inorder,postorder,0,index);
    }
    TreeNode* recursive(vector<int>& inorder, vector<int>& postorder, int begin, int end){
        TreeNode* root=new TreeNode(postorder[index]);
        if(begin==end) return root;
        int i;
        bool flag=false;
        for(i=begin;i<=end;i++){
            if(inorder[i]==root->val){
                flag=true;
                break;
            }
        }
        if(flag==false) return root;
        if(i==begin){
            index--;
            root->right=recursive(inorder,postorder,i+1,end);
        }
        else if(i==end){
            index--;
            root->left=recursive(inorder,postorder,begin,i-1);
        }
        else{
            index--;
            root->right=recursive(inorder,postorder,i+1,end);
            index--;
            root->left=recursive(inorder,postorder,begin,i-1);
        }
        return root;
    }
};