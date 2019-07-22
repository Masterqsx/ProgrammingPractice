package algorithm.binary_search;

import org.junit.Assert;
import org.junit.Test;

public class TestMyBinarySearchNextInsert {
    @Test
    public void testSearch() {
        int[] arr1 = new int[]{1, 3, 5, 6};

        Assert.assertEquals(2, MyBinarySearchNextInsert.search(arr1, 5));
        Assert.assertEquals(4, MyBinarySearchNextInsert.search(arr1, 7));
        Assert.assertEquals(0, MyBinarySearchNextInsert.search(arr1, 0));
    }
}
