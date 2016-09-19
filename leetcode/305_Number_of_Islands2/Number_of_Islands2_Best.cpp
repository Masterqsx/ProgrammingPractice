class Solution {
public:
    class unionfind{
    public:
        vector<int> array;
        vector<int> sz;
        int len;
        unionfind(int size) : len(size){
            array = vector<int>(size, 0);
            sz = vector<int>(size, 1);
            for (int i=0;i<size;i++) array[i] = i;
        }
        int root(int i){
            while (array[i] != i){
                array[i] = array[array[i]]; //this path compression operation will not compress the path at one time, each time we only link the original node to the grandparent and stop
                i = array[i];
            }
            return i;
        }
        bool connected(int i, int j){
            return root(i) == root(j);
        }
        void node_union(int i, int j, int &count){
            int root_i = root(i);
            int root_j = root(j);
            if (root_i == root_j) return;
            count--;
            if (sz[root_i] > sz[root_j]){
                array[root_j] = root_i;
                sz[root_i] += sz[root_j];
            }
            else{
                array[root_i] = root_j;
                sz[root_j] += sz[root_i];
            }
        }
    };
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (m == 0 || n == 0) return vector<int>();
        m += 2;
        n += 2;
        bool added[m*n] = {false};
        unionfind u = unionfind(m*n);
        vector<int> res;
        int count = 0;
        for (auto node : positions){
            int up = (node.first+1-1)*n+node.second+1, down = (node.first+1+1)*n+node.second+1, left = (node.first+1)*n+node.second+1-1, right = (node.first+1)*n+node.second+1+1, cur = (node.first+1)*n+node.second+1;
            added[cur] = true;
            if (!added[up] && !added[down] && !added[left] && !added[right]){
                count++;
                res.push_back(count);
                continue;
            }
            if (added[up]) u.node_union(cur, up, count);//do not forget, the union operation could decrease the count
            if (added[down]) u.node_union(cur, down, count);
            if (added[left]) u.node_union(cur, left, count);
            if (added[right]) u.node_union(cur, right, count);
            res.push_back(++count);//do not forget "++", each time we add a new element, we ++
        }
        return res;
    }
};