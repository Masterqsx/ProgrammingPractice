package algorithm.string;

import org.junit.Assert;
import org.junit.Test;

public class TestMySuffixArrayDoubly {
    private static final String str = "aabaaaab";
    private String str1 = "";
    private static final int[] expectedSA = new int[]{3, 4, 5, 0, 6, 1, 7, 2};
    private static final int[] expectedHeight = new int[]{0, 3, 2, 3, 1, 2, 0, 1};

    @Test
    public void testBuildSA() {
        MySuffixArrayDoubly msa = new MySuffixArrayDoubly();
        msa.buildSA(str);
        for (int i = 0; i < msa.sa.length; i++) Assert.assertEquals(expectedSA[i], msa.sa[i]);

    }

    @Test
    public void testBuildHeight() {
        MySuffixArrayDoubly msa = new MySuffixArrayDoubly();
        msa.buildSA(str);
        for (int i = 0; i < msa.height.length; i++) Assert.assertEquals(expectedHeight[i], msa.height[i]);
    }

    @Test
    public void test() {
        for (int i = 0; i < 100000; i++) str1 += "a";
        MySuffixArrayDoubly msa = new MySuffixArrayDoubly();
        msa.buildSA(str1);
    }
}
