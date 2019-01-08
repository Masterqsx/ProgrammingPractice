class Solution {
    public int compareVersion(String version1, String version2) {
        String[] digits1 = version1.split("\\.");
        String[] digits2 = version2.split("\\.");
        int i1 = 0, i2 = 0;
        for (int i = 0; i < Integer.max(digits1.length, digits2.length); i++) {
            if (i < digits1.length) i1 = Integer.parseInt(digits1[i]);
            if (i < digits2.length) i2 = Integer.parseInt(digits2[i]);
            if (i1 > i2) return 1;
            else if (i1 < i2) return -1;
            i1 = 0;
            i2 = 0;
        }
        return 0;
    }
}
