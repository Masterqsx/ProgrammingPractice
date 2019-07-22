class Solution {
    public int newDir(int idx, int change) {
        if (idx == 0 && change == -1) return 3;
        else if (idx == 3 && change == 1) return 0;
        else return idx + change;
    }
    public boolean isRobotBounded(String instructions) {
        int[][] dir = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIdx = 0;
        int x = 0, y = 0;
        for (int i = 0; i < instructions.length(); i++) {
            if (instructions.charAt(i) == 'L') dirIdx = newDir(dirIdx, -1);
            else if (instructions.charAt(i) == 'R') dirIdx = newDir(dirIdx, 1);
            else {
                x += dir[dirIdx][0];
                y += dir[dirIdx][1];
            }
        }
        return x == 0 && y == 0 || dirIdx > 0;
    }
}
