class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res = vector<int>(length, 0);
        for (int i = 0;i < updates.size();i++){
            res[updates[i][0]] += updates[i][2];
            if (updates[i][1] < length - 1) res[updates[i][1]+1] += -updates[i][2];
        }
        int cur = 0;
        for (int i = 0;i < length;i++){
            int t = res[i];
            res[i] += cur;
            cur += t;
        }
        return res;
    }
};
