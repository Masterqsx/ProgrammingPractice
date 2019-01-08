class Solution {
    public int cos(int[] p1, int[] p2) {
        return p1[0] * p2[0] + p1[1] * p2[1];
    }
    public int[] line(int[] p1, int[] p2) {
        int[] l = {p2[0] - p1[0], p2[1] - p1[1]};
        return l;
    }
    public double len(int[] l) {
        return Math.sqrt(l[0] * l[0] + l[1] * l[1]);
    }
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[] l12 = line(p1, p2);
        int[] l13 = line(p1, p3);
        int[] l14 = line(p1, p4);
        int[] l23 = line(p2, p3);
        int[] l24 = line(p2, p4);
        int[] l34 = line(p3, p4);
        if (len(l12) == 0 || len(l13) == 0 || len(l14) == 0 || len(l23) == 0 || len(l24) == 0 || len(l34) == 0) return false; 
        if (cos(l12, l13) == 0) {
            if (cos(l12, l24) == 0 && cos(l24, l34) == 0 && len(l12) == len(l24)) return true;
            else return false;
        } else if (cos(l12, l14) == 0) {
            if (cos(l12, l23) == 0 && cos(l23, l34) == 0 && len(l12) == len(l23)) return true;
            else return false;
        } else if (l13[0] * l14[0] + l13[1] * l14[1] == 0) {
            if (cos(l13, l23) == 0 && cos(l23, l24) == 0 && len(l14) == len(l24)) return true;
            else return false;
        } else return false;
    }
}
