class Solution {
    private void binaryReplace(List<Integer> digits, int targetIndex, int l, int r) { 
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (digits.get(mid) > digits.get(targetIndex)) l = mid;
            else r = mid - 1;
        }
        int temp = digits.get(targetIndex);
        digits.set(targetIndex, digits.get(l));
        digits.set(l, temp);
        Collections.sort(digits.subList(targetIndex + 1, digits.size()));
    }
    public int nextGreaterElement(int n) {
        int index = 0, max = 0;
        long res = n;
        List<Integer> digits = new LinkedList<>();
        while (res > 0) {
            int currentDigit = (int)res % 10;
            digits.add(0, currentDigit);
            res = res / 10;
            if (currentDigit < max) {
                binaryReplace(digits, 0, 1, digits.size() - 1);
                for (int i = 0; i < digits.size(); i++) res = res * 10 + digits.get(i);
                return res > Integer.MAX_VALUE ? -1 : (int)res;
            }
            max = currentDigit;
        }
        return -1;
    }
}
