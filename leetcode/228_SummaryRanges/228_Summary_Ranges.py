class Solution:
    def output(self, start, prev):
        if start == prev:
            return str(start)
        else:
            return str(start) + "->" + str(prev)
        
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return []
        start = nums[0]
        prev = nums[0]
        res = []
        for i in range(1, len(nums)):
            if nums[i] == prev + 1:
                prev = nums[i]
            else:
                res.append(self.output(start, prev))
                start = nums[i]
                prev = nums[i]
        if prev == nums[-1]:
            res.append(self.output(start, prev))
        return res
        
