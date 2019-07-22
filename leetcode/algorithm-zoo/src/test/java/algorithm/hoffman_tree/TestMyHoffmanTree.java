package algorithm.hoffman_tree;

import org.junit.Assert;
import org.junit.Test;

public class TestMyHoffmanTree {
    @Test
    public void testGetBinaryCode() {
        int[] arr1 = new int[]{8, 1, 4, 1, 5, 3};

        MyHoffmanTree tree = new MyHoffmanTree();

        String[] encoding = tree.getBinaryCode(arr1);
        encoding.clone();
        Assert.assertEquals(encoding[0], "11");
    }
}
