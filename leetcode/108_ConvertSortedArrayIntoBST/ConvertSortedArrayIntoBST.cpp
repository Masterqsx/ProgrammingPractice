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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums,0,nums.size()-1);
    }
    TreeNode* recursive(vector<int>& nums,int b,int e){
        if(b>e) return NULL;
        if(b==e) return (new TreeNode(nums[b]));
        int mid=b+(e-b)/2;
        TreeNode* re=new TreeNode(nums[mid]);
        re->left=recursive(nums,b,mid-1);
        re->right=recursive(nums,mid+1,e);
        return re;
    }
};