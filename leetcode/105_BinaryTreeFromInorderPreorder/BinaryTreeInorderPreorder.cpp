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
    int index=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if((preorder.size()==0)||(inorder.size()!=preorder.size())) return NULL;
        return recursive(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode* recursive(vector<int>& pre, vector<int>& in, int begin, int end){
        TreeNode* root=new TreeNode(pre[index]);
        if(begin==end) return root;
        int i,flag=false;
        for(i=begin;i<=end;i++){
            if(in[i]==pre[index]){
                flag=true;
                break;
            }
        }
        if(flag==false) return root;
        if(i==begin){
            root->left=NULL;
            index++;
            root->right=recursive(pre,in,i+1,end);
        }
        else if(i==end){
            root->right=NULL;
            index++;
            root->left=recursive(pre,in,begin,i-1);
        }
        else{
            index++;
            root->left=recursive(pre,in,begin,i-1);
            index++;
            root->right=recursive(pre,in,i+1,end);
        }
        return root;
    }
};