package algorithm.string;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class MyNFARegularExpressionLite {
    //This is the lite version of NFA Regular Expression Parser
    //This parser only support "Concatenation" (pattern string like "AB")
    // , "Parentheses" (pattern string like "(AB)")
    // , "Closure" (pattern string like "A*B")
    // , "Wildcard" (single character matcher ".")
    // and "Or" (pattern string like "A|B")
    //This State Machine uses char array to represent exact match and BFS in graph to support all the other keywords
    private char[] re;
    private Map<Integer, Set<Integer>> graph;

    public void buildNFA(String pattern) {
        //dummy parentheses always exist at the front and the end
        pattern = "(" + pattern + ")";
        re = pattern.toCharArray();
        graph = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        //This is save for the ending vertex
        //The index of ending vertex is re.length
        for (int i = 0; i <= re.length; i++) graph.put(i, new HashSet<>());
        for (int i = 0; i < re.length; i++) {
            int lp = i;
            if (re[i] == '(' || re[i] == '|') stack.push(i);
            if (re[i] == ')') {
                int op = stack.pop();
                if (re[op] == '|') {
                    lp = stack.pop();
                    graph.get(lp).add(op + 1);
                    graph.get(op).add(i);
                }
                else lp = op;
            }
            if (i < re.length - 1 && re[i + 1] == '*') {
                graph.get(lp).add(i + 1);
                graph.get(i + 1).add(lp);
            }
            if (re[i] == '(' || re[i] == '*' || re[i] == ')') graph.get(i).add(i + 1);
        }

    }

    public boolean recognize(String text) {
        Set<Integer> cur = new HashSet<>();
        boolean[] marked = new boolean[graph.size()];
        dfs(0, marked);
        for (int i = 0; i < marked.length; i++) {
            if (marked[i]) cur.add(i);
        }

        for (int i = 0; i < text.length(); i++) {
            Set<Integer> next = new HashSet<>();
            for (Integer v : cur) {
                if (text.charAt(i) == re[v] || re[v] == '.') next.add(v + 1);
            }
            cur = new HashSet<>();
            marked = new boolean[graph.size()];
            dfs(next, marked);
            for (int j = 0; j < marked.length; j++) {
                if (marked[j]) cur.add(j);
            }
        }

        for (Integer v : cur) if (v == re.length) return true;
        return false;
    }

    public void dfs(Iterable<Integer> sources, boolean[] marked) {
        for (Integer v : sources) {
            if (!marked[v]) dfs(v, marked);
        }
    }

    public void dfs(int source, boolean[] marked) {
        marked[source] = true;
        for (Integer v : graph.get(source)) {
            if (!marked[v]) dfs(v, marked);
        }
    }
}
