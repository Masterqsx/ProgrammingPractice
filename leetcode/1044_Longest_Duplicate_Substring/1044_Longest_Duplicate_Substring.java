class Solution {
    public class MySuffixArrayDoubly {
    public int[] sa;
    public int[] firstKeyRank;
    public int[] secondKeySA;
    public int[] count;
    public int[] height;
    public int[] rank;

    private void buildHeight(String str) {
        rank = new int[sa.length];
        for (int i = 0; i < sa.length; i++) rank[sa[i]] = i;
        height = new int[sa.length];
        height[0] = 0;
        int k = 0;
        for (int i = 0; i < sa.length; i++) {
            if (rank[i] == 0) continue;
            if (k != 0) k--;
            int j = sa[rank[i] - 1];
            while (i + k < str.length()
                && j + k < str.length()
                && str.charAt(i + k) == str.charAt(j + k)) k++;
            height[rank[i]] = k;
        }
    }

    public void buildSA(String str) {
        int bucketSz = Math.max(0x10000, str.length() + 1);
        sa = new int[str.length()];
        firstKeyRank = new int[str.length()];
        secondKeySA = new int[str.length()];
        count = new int[bucketSz];//0xFFFF + 1

        for (int i = 0; i < str.length(); i++) firstKeyRank[i] = (int)str.charAt(i);
        for (int i = 0; i < str.length(); i++) count[firstKeyRank[i] + 1]++;
        for (int i = 1; i < bucketSz; i++) count[i] += count[i - 1];
        for (int i = 0; i < str.length(); i++) sa[count[firstKeyRank[i]]++] = i;

        for (int doubly = 1; doubly <= str.length(); doubly <<= 1) {
            int j = 0;
            for (int i = str.length() - doubly; i < str.length(); i++) secondKeySA[j++] = i;
            for (int i = 0; i < str.length(); i++) {
                if (sa[i] >= doubly) secondKeySA[j++] = sa[i] - doubly;
            }

            int[] firstKeyRankOrderedBySecondKey = new int[str.length()];
            //After sorting the second key, retrieve the first key rank of current order, ready for sorting based on first key
            for (int i = 0; i < str.length(); i++) firstKeyRankOrderedBySecondKey[i] = firstKeyRank[secondKeySA[i]];
            for (int i = 0; i < bucketSz; i++) count[i] = 0;
            for (int i = 0; i < str.length(); i++) count[firstKeyRankOrderedBySecondKey[i] + 1]++;
            for (int i = 1; i < bucketSz; i++) count[i] += count[i - 1];
            for (int i = 0; i < str.length(); i++) sa[count[firstKeyRankOrderedBySecondKey[i]]++] = secondKeySA[i];


            int[] nextFirstKeyRank = new int[str.length()];
            nextFirstKeyRank[sa[0]] = 0;
            int rank = 0;
            for (int i = 1; i < str.length(); i++) {
                if (firstKeyRank[sa[i]] == firstKeyRank[sa[i - 1]]
                    && (
                        (sa[i] + doubly >= str.length() && sa[i - 1] + doubly >= str.length())
                        || (sa[i] + doubly < str.length() && sa[i - 1] + doubly < str.length() && firstKeyRank[sa[i] + doubly] == firstKeyRank[sa[i - 1] + doubly])
                        )
                    )
                    nextFirstKeyRank[sa[i]] = rank;
                else
                    nextFirstKeyRank[sa[i]] = ++rank;
            }
            for (int i = 0; i < str.length(); i++) firstKeyRank[i] = nextFirstKeyRank[i];

            if (rank >= str.length() - 1) break;

            bucketSz = rank + 1;


        }
        buildHeight(str);
    }
}
    
    public String longestDupSubstring(String S) {
        MySuffixArrayDoubly msa = new MySuffixArrayDoubly();
        msa.buildSA(S);
        int resIdx = 0;
        for (int i = 1; i < msa.height.length; i++) if (msa.height[i] > msa.height[resIdx]) resIdx = i;
        return S.substring(msa.sa[resIdx], msa.sa[resIdx] + msa.height[resIdx]);
    }
}
