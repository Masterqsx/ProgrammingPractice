class StreamChecker {
    class Node {
        public char c;
        public boolean end;
        public Map<Character, Node> next;
        public Node(char c) {this.c = c;next = new HashMap<>();}
    }
    Node root;
    List<Character> list;
    public StreamChecker(String[] words) {
        root = new Node('^');   
        for (int i = 0; i < words.length; i++) {
            Node cur = root;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                Character ch = new Character(words[i].charAt(j));
                if (!cur.next.containsKey(ch)) cur.next.put(ch, new Node(ch));
                cur = cur.next.get(words[i].charAt(j));
            }
            cur.end = true;
        }
        list = new ArrayList<>();
    }
    public boolean query(char letter) {
        list.add(letter);
        Node cur = root;
        for (int i = list.size() - 1; i >= 0; i--) {
            if (cur.next.containsKey(list.get(i))) cur = cur.next.get(list.get(i));
            else return false;
            if (cur.end) return true;
        }
        return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
