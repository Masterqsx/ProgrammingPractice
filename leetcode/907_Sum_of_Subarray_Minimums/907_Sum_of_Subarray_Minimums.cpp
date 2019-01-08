class Solution {
public:
    class node {
    public:
        int val = 0;
        int count = 0;
        node(int _val, int _count) {
            val = _val;
            count = _count;
        }
    };
    int sumSubarrayMins(vector<int>& A) {
        int MOD = (int)pow(10, 9) + 7;
        vector<node*> mStack;
        int res = 0, tempSum = 0;
        for (int i = 0; i < A.size(); i++) {
            node* n = new node(A[i], 1);
            while (!mStack.empty() && mStack.back()->val >= A[i]) {
                node* poped = mStack.back();
                mStack.pop_back();
                n->count += poped->count;
                tempSum -= poped->count * poped->val;
            }
            tempSum += n->count * n->val;
            tempSum %= MOD;
            mStack.push_back(n);
            res += tempSum;
            res %= MOD;
        }
        
        return res;
    }
};
