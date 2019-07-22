package algorithm.graph;

public class MyStableMatching {
    public static int[] findMatch(int[][] girl, int[][] boy) {
        int[] boyIdx = new int[boy.length];
        int[] girlChoice = new int[girl.length];
        for (int i = 0; i < girl.length; i++) girlChoice[i] = -1;

        int[][] girlBoyToPrecedence = new int[girl.length][boy.length];
        for (int i = 0; i < girl.length; i++) {
            for (int j = 0; j < boy.length; j++) {
                girlBoyToPrecedence[i][girl[i][j]] = j;
            }
        }
        //The boy keep finding worse and the girl keep finding better
        boolean hasSwitch = true;
        while (hasSwitch) {
            hasSwitch = false;
            for (int i = 0; i < boy.length; i++) {
                int curGirl = boy[i][boyIdx[i]];
                int curGirlMatch = girlChoice[curGirl];
                if (curGirlMatch == -1) {
                    girlChoice[curGirl] = i;
                    hasSwitch = true;
                }
                else if (curGirlMatch != i) {
                    if (girlBoyToPrecedence[curGirl][i] < girlBoyToPrecedence[curGirl][curGirlMatch]) {
                        girlChoice[curGirl] = i;
                        boyIdx[curGirlMatch]++;
                    } else boyIdx[i]++;
                    hasSwitch = true;
                }
            }
        }
        return girlChoice;
    }
}
