package algorithm.scheduling;

public class MyRoundRobin {
    private int cur;

    private int sz;

    private int[] weights;

    private int lksGranularity;

    private int lksMaxWeight;

    private int lksCurBound;

    private int[] nignxWeights;

    private int nignxWeightsSum;

    private int gcd (int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    public MyRoundRobin(int sz) {this.sz = sz;}

    public MyRoundRobin(int[] weights) {
        this.weights = new int[weights.length];
        nignxWeights = new int[weights.length];
        nignxWeightsSum = 0;
        for (int i = 0; i < weights.length; i++) {
            this.weights[i] = weights[i];
            nignxWeights[i] = weights[i];
            nignxWeightsSum += weights[i];
        }
        sz = weights.length;

        //For LKS weighted robin
        //The lksGranularity comes from gcd, each weights can be divided into multiple this variable
        if (sz > 0) lksGranularity = weights[0];
        if (sz > 0) lksMaxWeight = weights[0];
        for (int i = 1; i < weights.length; i++) {
            lksGranularity = gcd(lksGranularity, weights[i]);
            lksMaxWeight = Math.max(lksMaxWeight, weights[i]);
        }
        lksCurBound = lksMaxWeight;
    }

    public int equalPoll() {
        int res = cur;
        cur = (cur + 1) % sz;
        return res;
    }

    public int weightedPollLKS() {
        //So for each round we only select elements >= current bound
        //In each round one element will be selected once
        //During current bound reaching 0, each elements will be selected weight / gcd times
        while (weights[cur] < lksCurBound) lksGetNext();
        int res = cur;
        lksGetNext();
        return res;
    }

    private int lksGetNext() {
        //If we finish one round we need reduce current bound with granularity
        //If our current bound reach the 0, should be restored to max weight
        if (cur == sz - 1) {
            lksCurBound -= lksGranularity;
            if (lksCurBound <= 0) lksCurBound = lksMaxWeight;
        }
        cur = (cur + 1) % sz;
        return cur;
    }

    public int weightedPollNginx() {
        //on each peer selection we increase current_weight of each eligible peer by its weight
        //select peer with greatest current_weight and reduce its current_weight by total number of weight points distributed among peers.
        /*
         *   Intuition:
         *   Given weights {5, 1, 1}
         *   node 0: select x0 times, node1: select x1 times, node2: select x2 times
         *   node 0: 5 - 2 * x0 + 5 * (x1 + x2)
         *   node 1: 1 - 6 * x1 + 1 * (x0 + x2)
         *   node 2: 1 - 6 * x2 + 1 * (x0 + x1)
         *   When nignx weights reach their initial weights:
         *   - 2 * x0 + 5 * (x1 + x2) = 0
         *   - 6 * x1 + 1 * (x0 + x2) = 0
         *   - 6 * x2 + 1 * (x0 + x1) = 0
         *   x0 : x1 : x2 = 5 : 1 : 1 which is what we need
         */
        int maxIdx = 0;
        for (int i = 1; i < sz; i++) {
            if (nignxWeights[i] > nignxWeights[maxIdx]) maxIdx = i;
        }
        for (int i = 0; i < sz; i++) {
            if (i == maxIdx) nignxWeights[i] -= nignxWeightsSum - weights[i];
            else nignxWeights[i] += weights[i];
        }
        return maxIdx;
    }
}
