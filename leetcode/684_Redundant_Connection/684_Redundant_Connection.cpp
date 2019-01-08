class Solution {
public:
    class unionFind {
        public:
        vector<int> parent;
        vector<int> sz;
        unionFind() {}
        unionFind(int n) {
            for (int i = 0; i < n; i++) parent.push_back(i);
            sz = vector<int>(n, 1);
        }
        int root(int p) {
            while (parent[p] != p) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        void unite(int p, int q) {
            int rootP = root(p);
            int rootQ = root(q);
            if (sz[rootP] > sz[rootQ]) {
                parent[rootQ] = rootP;
                sz[rootP] += sz[rootQ];
            }
            else {
                parent[rootP] = rootQ;
                sz[rootQ] += sz[rootP];
            }
        }
        bool find(int p, int q) {
            return root(p) == root(q);
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unionFind uf = unionFind(edges.size() + 1);
        for (vector<int>& edge : edges) {
            if (uf.find(edge[0], edge[1])) return edge;
            uf.unite(edge[0], edge[1]);
        }
        return vector<int>(2, 0);
    }
};
