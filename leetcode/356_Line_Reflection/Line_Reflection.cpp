class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        unordered_map<double, set<int>> m;
        int mi = points[0].first, ma = points[0].first;
        for (auto co : points){
            mi = min(co.first, mi);
            ma = max(co.first, ma);
            m[co.first].insert(co.second);
        }
        double mid = (double)(mi + ma)/2;
        for (auto co : points){
            double r = 2 * mid - co.first;
            if (m.count(r) != 1 || m[r].count(co.second) != 1)
                return false;
        }
        return true;
    }
};