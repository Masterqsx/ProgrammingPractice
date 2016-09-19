/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        unordered_map<double, int > pattern;
        int res = 0;
        for (int i = 0;i<points.size();i++){
            pattern.clear();
            pattern[numeric_limits<double>::min()] = 0;
            int duplicate = 0;
            double slope = 0;
            for (int j = 0;j<points.size();j++){
                if (points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate++;
                    continue;
                }
                else if (points[i].x == points[j].x) slope = numeric_limits<double>::max();
                else slope = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x); //Should cast the type
                pattern[slope]++;
            }
            for (auto pa : pattern){
                res = max(res, pa.second + duplicate);
            }
        }
        return res;
    }
};