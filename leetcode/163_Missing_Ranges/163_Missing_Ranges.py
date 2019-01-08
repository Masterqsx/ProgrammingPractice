class Solution:
    def output(self, prev, cur):
        start = prev + 1
        end = cur - 1
        if start == end:
            return str(start)
        else:
            return str(start) + "->" + str(end)
        
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        res = []
        if len(nums) == 0:
            res.append(self.output(lower - 1, upper + 1))
            return res
        if lower < nums[0]:
            res.append(self.output(lower - 1, nums[0]))
        prev = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == prev:
                continue
            if nums[i] != prev + 1:
                res.append(self.output(prev, nums[i]))
            prev = nums[i]
        if upper > prev:
            res.append(self.output(prev, upper + 1))
        return res
