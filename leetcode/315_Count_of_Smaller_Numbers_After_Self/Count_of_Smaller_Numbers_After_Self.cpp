class Solution {
public:
    class node{
    public:
        int val;
        int times;
        int less;
        node* left;
        node* right;
        node(int _val):val(_val), times(1), less(0), left(NULL), right(NULL){};
        ~node(){
            delete left;
            delete right;
            return;
        }
    };
    void insert(node* root, int nb, int& res){
        if (nb > root->val){
            res += root->times + root->less;
            if (root->right != NULL) insert(root->right, nb, res);
            else root->right = new node(nb);
        }
        else if (nb < root->val){
            root->less++;
            if (root->left != NULL) insert(root->left, nb, res);
            else root->left = new node(nb);
        }
        else{
            res += root->less;
            root->times++;
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() < 1) return vector<int>();
        auto it = nums.rbegin();
        node* root = new node(*it);
        it++;
        vector<int> temp({0});
        while (it != nums.rend()){
            int res = 0;
            insert(root, *it, res);
            temp.push_back(res);
            it++;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
