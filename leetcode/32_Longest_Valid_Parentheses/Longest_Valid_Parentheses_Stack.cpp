class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> para;
        int pre = 0, ma = 0;
        for(int i=0;i<s.size();i++){
            if (s[i] == ')' && !para.empty() && s[para.top()] == '('){
                para.pop();
                pre = para.empty()?-1:para.top();
                ma = max(ma, i-pre);
            }
            else para.push(i);
        }
        return ma;
    }
};