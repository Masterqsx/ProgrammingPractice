class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int[][] heightMatrix = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == '0') heightMatrix[i][j] = 0;
                else heightMatrix[i][j] = (i > 0 ? heightMatrix[i - 1][j] : 0) + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < heightMatrix.length; i++) {
            Stack<Integer> st = new Stack<>();
            for (int j = 0; j < heightMatrix[i].length; j++) {
                while (!st.empty() && heightMatrix[i][j] <= heightMatrix[i][st.peek()]) {
                    int index = st.pop();
                    res = Math.max(res, (j - (st.empty() ? -1 : st.peek()) - 1) * heightMatrix[i][index]);
                }
                st.push(j);
            }
            while (!st.empty()) {
                int index = st.pop();
                res = Math.max(res, (heightMatrix[i].length - (st.empty() ? -1 : st.peek()) - 1) * heightMatrix[i][index]);
            }
        }
        return res;
    }
}
