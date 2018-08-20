class Solution {
    public List<String> removeComments(String[] source) {
        List<String> res = new ArrayList<>();
        int state = 0;
        StringBuffer buf = new StringBuffer();
        for (String line : source) {  
            for (int i = 0; i < line.length(); i++) {
                if (state == 0 && line.charAt(i) == '"') state = 1;
                if (state == 1 && line.charAt(i) == '"') state = 0;
                if (state == 0 && i < line.length() - 1 && line.charAt(i) == '/' && line.charAt(i + 1) == '*') {
                    state = 2;
                    i+= 2;
                }
                else if (state == 2 && i > 0 && line.charAt(i - 1) == '*' && line.charAt(i) == '/') state = 4;
                if (state == 0 && i < line.length() - 1 && line.charAt(i) == '/' && line.charAt(i + 1) == '/') state = 3;
                if (state == 3 && i == line.length() - 1) state = 4;
                
                if (state == 2 || state == 3 || state == 4) {
                    if (state == 4) state = 0;
                    continue;
                }
                buf.append(line.charAt(i));
            }
            if (buf.length() != 0 && state != 2) {
                res.add(buf.toString());
                buf = new StringBuffer();
            }
        }
        
        return res;
    }
}
