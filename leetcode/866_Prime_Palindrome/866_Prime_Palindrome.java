class Solution {
    public int reverse(int N) {
        int res = 0;
        while (N > 0) {
            res = res * 10 + N % 10;
            N /= 10;
        }
        return res;
    }
    
    public boolean isPalin(int N) {
        return N == reverse(N);    
    }
    
    public boolean isPrime(int N) {
        if (N < 2) return false;
        if (N % 2 == 0 && N != 2) return false;
        int temp = 3;
        while (temp * temp <= N) {
            if (N % temp == 0) return false;
            temp += 2;
        }
        return true;
    }
    
    public int primePalindrome(int N) {
        for (double rootL = 1; rootL <= 5; rootL++) {
            //odd loop
            int shiftOdd = (int)Math.pow(10.0, rootL - 1.0);
            int shiftEven = (int)Math.pow(10.0, rootL);
            int end = shiftEven;
            for (int root = (int)Math.pow(10.0, rootL - 1.0); root < end; root++) {
                int postFix = reverse(root);
                int temp = root * shiftOdd + postFix % shiftOdd;
                if (temp >= N && isPrime(temp)) return temp;
            }
            //even loop
            for (int root = (int)Math.pow(10.0, rootL - 1.0); root < end; root++) {
                int postFix = reverse(root);
                int temp = root * shiftEven + postFix;
                if (temp >= N && isPrime(temp)) return temp;
            }
        }
        return 0;
    }
}
