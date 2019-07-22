package algorithm.graph;

import org.junit.Assert;
import org.junit.Test;

public class TestMyStableMatching {
    private int[][] boy = new int[][]{{2,3,1,0},{2,1,3,0},{0,2,3,1},{1,3,2,0}};
    private int[][] girl = new int[][]{{0,3,2,1},{0,1,2,3},{0,2,3,1},{1,0,3,2}};
    @Test
    public void testFindMatch() {
        int[] girlMatch = MyStableMatching.findMatch(girl, boy);
        int[] boyMatch = new int[boy.length];
        for (int i = 0; i < girlMatch.length; i++) {
            boyMatch[girlMatch[i]] = i;
        }
        int[][] boyPrece = new int[boy.length][girl.length];
        int[][] girlPrece = new int[girl.length][boy.length];
        for (int i = 0; i < boy.length; i++) {
            for (int j = 0; j < girl.length; j++) {
                boyPrece[i][boy[i][j]] = j;
                girlPrece[i][girl[i][j]] = j;
            }
        }
        for (int i = 0; i < boy.length; i++) {
            for (int j = 0; j < girl.length; j++) {
                //The way to verify if it is a stable match is to find if there is a pair that both of them find each other is better than the current one
                Assert.assertFalse(boyPrece[i][boyMatch[i]] > boyPrece[i][j] && girlPrece[j][girlMatch[j]] > girlPrece[j][i]);
            }
        }
    }
}
