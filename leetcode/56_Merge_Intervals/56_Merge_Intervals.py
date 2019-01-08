# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def val(self, interval):
        return interval.start
    
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if intervals == None or len(intervals) == 0:
            return intervals
        
        intervals.sort(key = self.val)
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i].start <= res[-1].end:
                res[-1].end = max(intervals[i].end, res[-1].end)
            else:
                res.append(intervals[i]);
            
        return res
        
