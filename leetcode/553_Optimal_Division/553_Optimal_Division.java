class Solution {
    public String optimalDivision(int[] nums) {
        StringBuffer res = new StringBuffer();
        res.append(Integer.toString(nums[0]));
        if (nums.length > 1) res.append("/");
        if (nums.length > 2) res.append("(");
        for (int i = 1; i < nums.length; i++) {
            if (i != 1) res.append("/");
            res.append(Integer.toString(nums[i]));
        }
        if (nums.length > 2) res.append(")");
        return res.toString();
    }
}
