package algorithm.skiplist;

import org.junit.Assert;
import org.junit.Test;

import java.util.List;

public class TestMySkipList {

    private static int[] vals = new int[]{22, 19, 7, 3, 37, 11, 26};

    private static String[] keys = new String[]{"a", "b", "c", "d", "e", "f", "g"};

    @Test
    public void test() {
        MySkipList skipList = new MySkipList();
        for (int i = 0; i < vals.length; i++) {
            skipList.insert(keys[i], vals[i]);
        }
        for (int i = 0; i < vals.length; i++) {
            Assert.assertEquals(keys[i], skipList.search(vals[i], vals[i]).get(0));
        }
        skipList.delete("b");
        List<String> res = skipList.search(15, 26);
        Assert.assertEquals("g", res.get(0));
        Assert.assertEquals("a", res.get(1));
    }
}
