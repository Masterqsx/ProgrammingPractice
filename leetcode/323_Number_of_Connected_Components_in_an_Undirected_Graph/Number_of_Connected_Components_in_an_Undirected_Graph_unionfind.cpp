class Solution {
public:
    class unionfind{
    public:
        int* array;
        int* size;
        unionfind(int n){
            array = new int[n];
            size = new int[n];
            for (int i=0;i<n;i++){
                array[i] = i;
                size[i] = 1;
            }
        }
        ~unionfind(){
            delete [] array;
            delete [] size;
        }
        int parent(int cur){
            while (cur != array[cur]){
                array[cur] = array[array[cur]];
                cur = array[cur];
            }
            return cur;
        }
        void union_op(int n1, int n2){
            int p1 = parent(n1), p2 = parent(n2);
            if (p1 == p2) return;
            if (size[p1] >= size[p2]){
                array[p2] = p1;
                size[p1] += size[p2];
            }
            else{
                array[p1] = p2;
                size[p2] += size[p1];
            }
        }
        int is_union(int n1, int n2){
            return parent(n1) == parent(n2);
        }
    };
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (edges.empty()) return n;
        int res = 0;
        unionfind u = unionfind(n);
        for (auto pa : edges) u.union_op(pa.first, pa.second);
        for (int i=0;i<n;i++){
            if (u.array[i] == i) res++;
        }
        return res;
    }
};
