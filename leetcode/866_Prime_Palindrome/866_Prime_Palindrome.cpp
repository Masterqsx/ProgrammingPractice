class Solution {
public:
    int palinStartLength(int N) {
        int length = 0;
        while (N > 0) {
            N /= 10;
            length++;
        }
        return length;
    }
    
    int reverse(int N) {
        int r = 0;
        while (N > 0) {
            r = r * 10 + N % 10;
            N /= 10;
        }
        return r;
    }
    
    bool isPrime(int N) {
        if (N < 2 || N % 2 == 0) return false;
        int temp = 3;
        while (temp * temp <= N) {
            if (N % temp == 0) return false;
            temp += 2;
        }
        return true;
    }
    int primePalindrome(int N) {
        if (N <= 2) return 2;
        if (N <= 3) return 3;
        if (N <= 5) return 5;
        if (N <= 7) return 7;
        if (N <= 11) return 11;
        int palinRootLength = palinStartLength(N) / 2 + 1;
        for (int l = palinRootLength; l < 6; l++) {
            int shift = pow(10, l - 1);
            for (int i = pow(10, l - 1); i < pow(10, l); i++) {
                int rev = reverse(i);
                int temp1 = i * shift + rev % shift;
                if (isPrime(temp1) && temp1 >= N) return temp1;
            }
        }
        return 0;
    }
};
