class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        int lim = INT_MIN;
        vector<int> sta;
        for (int node : preorder) {
            if (node < lim) return false;
            while (sta.size() > 1 && sta.back() < node && sta[sta.size()-2] < node) sta.pop_back();//[40,20,10,35]
            if (!sta.empty() && node > sta.back()) {//[3,1,2]
                lim = sta.back();
                sta.pop_back();
            }
            sta.push_back(node);
        }
        return true;
    }
};
