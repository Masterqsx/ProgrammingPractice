# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        res = []
        temp = newInterval
        i = 0
        flag = 0
        while i < len(intervals):
            if temp.start <= intervals[i].end and intervals[i].start <= temp.end:
                temp.start = min(intervals[i].start, temp.start)
                temp.end = max(intervals[i].end, temp.end)
                i += 1
            elif flag != 1 and temp.end < intervals[i].start:
                res.append(temp)
                flag = 1
            else:
                res.append(intervals[i])
                i += 1
        if flag != 1:
            res.append(temp)
        return res
