/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> res = new ArrayList<>();
        Interval cur = newInterval;
        boolean flag = false;
        for (Interval interval : intervals) {
            if (cur.end >= interval.start && interval.end >= cur.start) {
                cur.start = Math.min(cur.start, interval.start);
                cur.end = Math.max(cur.end, interval.end);
            }
            else {
                if (cur.end < interval.start && !flag) {
                    res.add(cur);
                    flag = true;
                }
                res.add(interval);
            }
        }
        if (!flag) res.add(cur);
        return res;
    }
}
