class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        ArrayList<Integer> cur = new ArrayList<>();
        ArrayList<Integer> stack = new ArrayList<>();
        stack.add(1);
        while (!stack.isEmpty()) {
            if (cur.size() == k) {
                res.add(new ArrayList<Integer>(cur));
                stack.remove(stack.size() -1);
                cur.remove(cur.size() - 1);
                stack.set(stack.size() - 1, stack.get(stack.size() - 1) + 1);
            }
            else if (stack.get(stack.size() - 1) > n) {
                stack.remove(stack.size() -1);
                if(cur.size() > 0) cur.remove(cur.size() - 1);
                if(stack.size() > 0) stack.set(stack.size() - 1, stack.get(stack.size() - 1) + 1);
            } 
            else {
                int temp = stack.get(stack.size() - 1);
                cur.add(temp);
                stack.add(temp + 1);
            }
        }
        return res;
    }
}
