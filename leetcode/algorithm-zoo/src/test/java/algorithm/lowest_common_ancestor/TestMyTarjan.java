package algorithm.lowest_common_ancestor;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import utility.Node;
import utility.buildBinaryTree;

import java.util.List;
import java.util.stream.Collectors;

public class TestMyTarjan {

    private Node root;

    private Integer[] tree = new Integer[]{1, 2, 3, null, null, 4, 5, null, null, null, 6, 7, null, 8, null, null, null};

    private int[][] querys = new int[][]{{3, 4}, {3, 5}, {5, 6}, {6, 7}, {1, 8}, {1, 1}};

    private int[][] expected = new int[][]{{1, 1, 1}, {1, 8, 1}, {3, 4, 2}, {3, 5, 2}, {5, 6, 1}, {6, 7, 6}};

    private MyTarjan lca = new MyTarjan();

    @Before
    public void setUp() {
        root = buildBinaryTree.build(tree);
    }

    @Test
    public void testLca() {
        List<int[]> res = lca.lca(root, querys);

        res = res.stream().map(pair -> {
            int temp = pair[0];
            if (pair[0] > pair[1]) {
                pair[0] = pair[1];
                pair[1] = temp;
            }
            return pair;
        }).sorted((l, r) -> {
            if (l[0] != r[0]) return l[0] - r[0];
            if (l[1] != r[1]) return l[1] - r[1];
            else return l[2] - r[2];
        }).collect(Collectors.toList());

        for (int i = 0; i < res.size(); i++) {
            Assert.assertEquals(expected[i][0], res.get(i)[0]);
            Assert.assertEquals(expected[i][1], res.get(i)[1]);
            Assert.assertEquals(expected[i][2], res.get(i)[2]);
        }
    }
}
