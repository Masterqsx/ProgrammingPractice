class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            while (!st.empty() && heights[i] <= heights[st.peek()]) { 
                int index = st.pop();
                int startIndex = st.empty() ? -1 : st.peek();
                res = Math.max(res, (i - startIndex - 1) * heights[index]);
            }
            st.push(i);
        }
        int endIndex = heights.length;
        while (!st.empty()) {
            int index = st.pop();
            int startIndex = st.empty() ? -1 : st.peek();
            res = Math.max(res, (endIndex - startIndex - 1) * heights[index]);
        }
        
        return res;
    }
}
