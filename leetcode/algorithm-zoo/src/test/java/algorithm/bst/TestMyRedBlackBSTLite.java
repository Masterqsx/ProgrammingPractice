package algorithm.bst;

import algorithm.bst.MyRedBlackBSTLite;
import org.junit.Assert;
import org.junit.Test;

public class TestMyRedBlackBSTLite {
    @Test
    public void testInsert() {
        MyRedBlackBSTLite bst = new MyRedBlackBSTLite();
        int max = 100000;
        int min = -1 * max;

        for (int i = 0; i < 10000; i++) {
            bst.insert((int)Math.random() * (max - min + 1) + min);
        }
        Assert.assertTrue(bst.isBalance() && bst.isBST());
    }
}
