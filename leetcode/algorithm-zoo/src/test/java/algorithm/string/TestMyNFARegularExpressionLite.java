package algorithm.string;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestMyNFARegularExpressionLite {
    @Test
    public void testRecognize() {
        MyNFARegularExpressionLite re = new MyNFARegularExpressionLite();
        re.buildNFA("(A*B|AC)D");
        assertTrue(re.recognize("AABD"));
        assertTrue(re.recognize("ABD"));
        assertFalse(re.recognize("ABCCBD"));
        assertFalse(re.recognize("AC"));
        re.buildNFA("(a|aa)*b");
        //NFA use space to save time, the cases below will make DFA stall
        assertFalse(re.recognize("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"));
        assertFalse(re.recognize("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"));
    }
}
