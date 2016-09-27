class Solution {
public:
    int option = 0;
    bool visited[9];
    int numberOfPatterns(int m, int n) {
        if (n < m || m < 1 || n > 9) return 0;
        for (int i=0;i<9;i++) visited[i] = false;
        helper(-1, 0, m, n);
        return option;
    }
    void helper(int index, int count, int m, int n){
        if (count >=m && count <= n) option++;
        if (count > n) return;
        int m0 = index / 3, n0 = index % 3;
        for (int i=0;i<9;i++){
            int m1 = i / 3, n1 = i % 3;
            if (i == index || (index != -1 && (m1 + m0) % 2 == 0 && (n1 + n0) % 2 == 0 && visited[(m1+m0)/2 * 3 + (n1+n0)/2] == false) || visited[i]) continue;
            visited[i] = true;
            helper(i, count+1, m, n);
            visited[i] = false;
        }
    }
};
