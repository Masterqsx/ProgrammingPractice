class Solution {
    public int scoreOfParentheses(String S) {
        Stack<String> pStack = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '(') pStack.push("(");
            else if (S.charAt(i) == ')') {
                if (pStack.empty()) return 0;
                else if (pStack.peek().equals("(")) {
                    pStack.pop();
                    pStack.push("1");
                }
                else {
                    int res = 0;
                    while (!pStack.empty() && !pStack.peek().equals("(")) {
                        res += Integer.parseInt(pStack.pop());
                    }
                    if (!pStack.empty()) {
                        res *= 2;
                        pStack.pop();
                    }
                    pStack.push(Integer.toString(res));
                }
            }
        }
        if (pStack.size() < 1) return 0;
        else if (pStack.size() == 1) return Integer.parseInt(pStack.peek());
        else {
            int res = 0;
            while (!pStack.empty()) res += Integer.parseInt(pStack.pop());
            return res;
        }
    }
}
