package utility;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class buildBinaryTree {
    public static Node build(Integer[] arr) {
        Stack<Node> parents = new Stack<>();
        Map<Node, Integer> counts = new HashMap<>();
        int idx = 0;
        while (idx < arr.length) {
            Node n = null;
            if (arr[idx] != null) {
                n = new Node(arr[idx]);
                counts.put(n, 0);
            }
            while (!parents.empty() && counts.get(parents.peek()) >= 2) parents.pop();
            if (!parents.empty()) {
                if (counts.get(parents.peek()) == 0) parents.peek().left = n;
                else parents.peek().right = n;
                counts.put(parents.peek(), counts.get(parents.peek()) + 1);
            }
            if (arr[idx] != null) parents.push(n);
            idx++;
        }
        return parents.get(0);
    }
}
