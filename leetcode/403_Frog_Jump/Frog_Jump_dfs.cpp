class Solution {
public:
    unordered_map<unsigned long long, bool> dp;
    bool help(vector<int>& stones,int start,int k){
        if (start==stones.size()-1) return true;
        int key = start | k << 11;
        if (dp.count(key)) return dp[key];
        for (int i=start+1;i<stones.size();i++){
            if (stones[i]-stones[start]<k-1) continue;
            if (stones[i]-stones[start]>k+1) break;
            if (help(stones,i,stones[i]-stones[start])){
                dp[key] = true;
                return true;
            }
        }
        dp[key] = false;
        return false;
    }
    bool canCross(vector<int>& stones) {
        if (stones.size()<=1) return 1;
        int start = 0,k = 0;   // k is the steps when jumping to current stone.
        return help(stones,start,k);
    }
};
