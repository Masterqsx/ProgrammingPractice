class Solution {
    public boolean isBoomerang(int[][] points) {
        int[] l1 = new int[]{points[1][0] - points[0][0], points[1][1] - points[0][1]};
        int[] l2 = new int[]{points[2][0] - points[1][0], points[2][1] - points[1][1]};
        int[] l3 = new int[]{points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return (l1[0] != 0 || l1[1] != 0)
            && (l2[0] != 0 || l2[1] != 0)
            && (l3[0] != 0 || l3[1] != 0)
            && (l2[1] * l1[0] - l2[0] * l1[1] != 0);
    }
}
