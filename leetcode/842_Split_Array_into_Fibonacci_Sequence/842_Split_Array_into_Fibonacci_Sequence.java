class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> res = new ArrayList<>();
        if (bp(S, res)) return res;
        else return new ArrayList<>();
    }
    
    private boolean bp(String str, List<Integer> res) {
        if (str.length() <= 0 && res.size() > 2) return true;
        for (int sz = 1; sz <= str.length(); sz++) {
            try {
                if (res.size() < 2 
                    || res.get(res.size() - 1) + res.get(res.size() - 2) == Integer.parseInt(str.substring(0, sz))) {
                    if (str.substring(0, sz).charAt(0) == '0' && sz > 1) return false;
                        res.add(Integer.parseInt(str.substring(0, sz)));
                    if (bp(str.substring(sz), res)) return true;
                    else res.remove(res.size() - 1);
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return false;
    }
}
