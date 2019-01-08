class Solution {
    public NestedInteger deserialize(String s) {
        Stack<Character> charStack = new Stack<>();
        Stack<NestedInteger> intStack = new Stack<>();
        StringBuffer buf = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) - '0' < 10 && s.charAt(i) - '0' >= 0 || s.charAt(i) == '-') buf.append(s.charAt(i));
            else if (s.charAt(i) == ',') {
                if (buf.length() > 0) {
                    intStack.push(new NestedInteger(Integer.parseInt(buf.toString())));
                    buf = new StringBuffer();
                }
                charStack.push(s.charAt(i));
            }
            else if (s.charAt(i) == '[') charStack.push(s.charAt(i));
            else if (s.charAt(i) == ']') {
                if (buf.length() > 0) {
                    intStack.push(new NestedInteger(Integer.parseInt(buf.toString())));
                    buf = new StringBuffer();
                }
                NestedInteger intNested = new NestedInteger();               
                Stack<NestedInteger> temp = new Stack<>();
                if (s.charAt(i - 1) != '[') temp.push(intStack.pop());
                while(!charStack.peek().equals(Character.valueOf('['))) {
                    if (charStack.peek().equals(Character.valueOf(','))) {
                        temp.push(intStack.pop());
                    }
                    charStack.pop();
                }
                charStack.pop();
                while (temp.size() > 0) intNested.add(temp.pop());
                intStack.push(intNested);
            }
        }
        if (buf.length() > 0) return new NestedInteger(Integer.parseInt(buf.toString()));
        else return intStack.pop();
    }
}
