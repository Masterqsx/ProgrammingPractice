# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def getStart(self, interval):
        return interval.start
    
    def getEnd(self, interval):
        return interval.end
    
    def startOp(self, temp, cur):
        if cur.start not in temp:
            temp[cur.start] = 0
        temp[cur.start] += 1
        self.tempSize += 1
        self.res = max(self.res, self.tempSize)
    
    def endOp(self, temp, cur):
        self.tempSize -= 1
        if temp[cur.start] > 1:
            temp[cur.start] -= 1
    
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        startList = sorted(intervals, key=self.getStart)
        endList = sorted(intervals, key=self.getEnd)
        startIndex = 0
        endIndex = 0
        length = len(intervals);
        temp = {}
        self.res = 0
        self.tempSize = 0
        while startIndex < length or endIndex < length:
            if endIndex >= length:
                cur = startList[startIndex]
                self.startOp(temp, cur)
                startIndex += 1
            elif startIndex >= length:
                cur = endList[endIndex]
                self.endOp(temp, cur)
                endIndex += 1
            elif startList[startIndex].start < endList[endIndex].end:
                cur = startList[startIndex]
                self.startOp(temp, cur)
                startIndex += 1
            elif startList[startIndex].start >= endList[endIndex].end:
                cur = endList[endIndex]
                self.endOp(temp, cur)
                endIndex += 1
        return self.res
                
                
