class Solution {
    public List<Integer> binaryAdd(int[] arr1, int[] arr2) {
        int carry = 0;
        List<Integer> res = new ArrayList<>();
        for (int i = arr1.length - 1, j = arr2.length - 1; i >= 0 || j >= 0 || carry != 0;) {
            if (i >= 0) {
                carry += arr1[i];
                i--;
            }
            if (j >= 0) {
                carry += arr2[j];
                j--;
            }
            res.add(carry & 1);
            carry = - (carry >> 1);
        }
        return res;
    }
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        List<Integer> res = binaryAdd(arr1, arr2);
        while (res.size() > 1 && res.get(res.size() - 1) == 0) res.remove(res.size() - 1);
        int[] r = new int[res.size()];
        for (int i = res.size() - 1; i >= 0; i--) r[i] = res.get(res.size() - 1 - i);
        return r;
    }
}
