package algorithm.lowest_common_ancestor;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import utility.Node;
import utility.buildBinaryTree;

public class TestMyBinaryIndexLCA {
    private Node root;

    private Integer[] tree = new Integer[]{1, 2, 3, null, null, 4, 5, null, null, null, 6, 7, null, 8, null, null, null};

    private int[][] querys = new int[][]{{3, 4}, {3, 5}, {5, 6}, {6, 7}, {1, 8}, {1, 1}};

    private int[][] expected = new int[][]{{1, 1, 1}, {1, 8, 1}, {3, 4, 2}, {3, 5, 2}, {5, 6, 1}, {6, 7, 6}};

    private MyBinaryIndexLCA lca;

    @Before
    public void setUp() {
        root = buildBinaryTree.build(tree);
        lca = new MyBinaryIndexLCA(root);
    }

    @Test
    public void testLCA() {
        for (int[] e : expected) {
            Assert.assertEquals(e[2], lca.lca(e[0], e[1]));
        }
    }
}
