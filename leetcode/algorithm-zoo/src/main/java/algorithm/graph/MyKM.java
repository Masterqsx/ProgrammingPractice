package algorithm.graph;

import java.util.Arrays;

public class MyKM {
    //Will only get one possible result, if there are multiple perfect match
    public static int[] solve(int[][] table) {
        //Assume len(x) <= len(y)
        int[] xMatch = new int[table.length];
        Arrays.fill(xMatch, -1);
        int[] yMatch = new int[table[0].length];
        Arrays.fill(yMatch, -1);
        int[] xLabel = new int[table.length];
        int[] yLabel = new int[table[0].length];

        init(xLabel, table);
        km(xMatch, yMatch, xLabel, yLabel, table);
        return xMatch;
    }

    private static void init(int[] xLabel, int[][] table) {
        for (int i = 0; i < table.length; i++) {
            xLabel[i] = Integer.MIN_VALUE;
            for (int j = 0; j < table[i].length; j++) {
                if (table[i][j] > xLabel[i]) xLabel[i] = table[i][j];
            }
        }
    }

    //This variable is for check the minimum adjust during dfs if we want to add more edges
    //This value should be larger than zero always
    private static int adjust = Integer.MAX_VALUE;

    private static void km(int[] xMatch, int[] yMatch, int[] xLabel, int[] yLabel, int[][] table) {
        for (int i = 0; i < xMatch.length; i++) {
            boolean[] xVisited = new boolean[xMatch.length];
            boolean[] yVisited = new boolean[yMatch.length];
            adjust = Integer.MAX_VALUE;
            //Each dfs will match one more x point
            while (!dfs(i, xMatch, yMatch, xLabel, yLabel, table, xVisited, yVisited)) {
                adjustXYLabel(xVisited, yVisited, xLabel, yLabel);
                Arrays.fill(xVisited, false);
                Arrays.fill(yVisited, false);
                adjust = Integer.MAX_VALUE;
            }
        }
    }

    private static void adjustXYLabel(boolean[] xVisited, boolean[] yVisited, int[] xLabel, int[] yLabel) {
        //if both points in x or y are on the augmenting path, xlabel - d + ylabel + d, the choice of edge stage the same, conflict point still stay
        //if only point in x are on the augment path, xlabel - d + ylabel, we make the old optimal choice unconsidered, but we may find or not the edge == xlabel - d + ylabe
        //if only point in y are on the augment path, xlabel + ylabel + d, we make the x points not on the augmenting path not choose these popular y points, need more gain
        //if both not on the augment path, no change
        for (int i = 0; i < xVisited.length; i++) if (xVisited[i]) xLabel[i] -= adjust;
        for (int j = 0; j < yVisited.length; j++) if (yVisited[j]) yLabel[j] += adjust;
    }

    private static boolean dfs(int x, int[] xMatch, int[] yMatch, int[] xLabel, int[] yLabel, int[][] table, boolean[] xVisited, boolean[] yVisited) {
        xVisited[x] = true;
        for (int i = 0; i < yMatch.length; i++) {
            if (!yVisited[i]) {
                int tmp = xLabel[x] + yLabel[i] - table[x][i];
                if (tmp == 0) { //Only the edge with tmp == 0 is the edge should be considered
                    yVisited[i] = true;
                    if (yMatch[i] == -1 || dfs(yMatch[i], xMatch, yMatch, xLabel, yLabel, table, xVisited, yVisited)) {
                        xMatch[x] = i;
                        yMatch[i] = x;
                        return true;
                    }
                    //If tmp is less than 0, which should not be considered
                    //If tmp is larger than zero which means the edge is our potential choice but the our best
                    //So during each search we always search the minimum cost for relax our constrains to allow less optimal edges come in
                } else if (tmp > 0) adjust = Math.min(adjust, tmp);
            }
        }
        return false;
    }
}
