class Solution {
private:
    stack<int> index_stack;
    int max_area = 0;
public:
    void calculate_area(vector<int>& heights, int i){
        int cur = index_stack.top();
        index_stack.pop();
        if (!index_stack.empty())
            max_area = max(max_area, (i - index_stack.top() - 1) * heights[cur]);
        else
            max_area = max(max_area, i * heights[cur]);
    }
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return max_area;
        int i = 0;
        max_area = 0;
        for (;i<heights.size();i++){
            while (!index_stack.empty() && heights[i] < heights[index_stack.top()])
                calculate_area(heights, i);
            index_stack.push(i);
        }
        while (!index_stack.empty())
            calculate_area(heights, i);
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        vector<int> line = vector<int>(matrix[0].size(), 0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if (matrix[i][j] == '0') line[j] = 0;
                else line[j] += 1;
            }
            res = max(res, largestRectangleArea(line));
        }
        return res;
    }
};