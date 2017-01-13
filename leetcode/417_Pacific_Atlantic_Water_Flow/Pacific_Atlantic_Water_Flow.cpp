class Solution {
public:
    unordered_set<int> visited1;
    unordered_set<int> visited2;
    vector<vector<pair<bool, bool>>> reached;
    int h;
    int w;
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        h = matrix.size();
        if (h == 0) return vector<pair<int, int>>();
        w = matrix[0].size();
        if (w == 0) return vector<pair<int, int>>();
        vector<pair<int, int>> res;
        reached = vector<vector<pair<bool, bool>>>(h, vector<pair<bool, bool>>(w, pair<bool, bool>({false, false})));
        for (int i=0;i<h;i++){
            queue<int> next1({i*w}), next2({(h-i-1)*w+w-1});
            visited1.insert(i*w);
            visited2.insert((h-i-1)*w+w-1);
            reached[i][0].first = true;
            reached[h-i-1][w-1].second = true;
            bfs1(matrix, next1);
            bfs2(matrix, next2);
        }
        for (int j=0;j<w;j++){
            queue<int> next1({j}), next2({(h-1)*w+w-1-j});
            visited1.insert(j);
            visited2.insert((h-1)*w+w-1-j);
            reached[0][j].first = true;
            reached[h-1][w-j-1].second = true;
            bfs1(matrix, next1);
            bfs2(matrix, next2);
        }
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                if (reached[i][j].first && reached[i][j].second) res.push_back(pair<int, int>({i, j}));
            }
        }
        return res;
    }
    void bfs1(vector<vector<int>>& matrix, queue<int>& next){
        while (!next.empty()){
            int i = next.front()/w, j = next.front()%w;
            if (i < h-1 && visited1.count((i+1)*w+j) == 0 && matrix[i][j] <= matrix[i+1][j]){
                reached[i+1][j].first = true;
                next.push((i+1)*w+j);
                visited1.insert((i+1)*w+j);
            }
            if (j < w-1 && visited1.count(i*w+j+1) == 0 && matrix[i][j] <= matrix[i][j+1]){
                reached[i][j+1].first = true;
                next.push(i*w+j+1);
                visited1.insert(i*w+j+1);
            }
            if (i > 0 && visited1.count((i-1)*w+j) == 0 && matrix[i][j] <= matrix[i-1][j]){
                reached[i-1][j].first = true;
                next.push((i-1)*w+j);
                visited1.insert((i-1)*w+j);
            }
            if (j > 0 && visited1.count(i*w+j-1) == 0 && matrix[i][j] <= matrix[i][j-1]){
                reached[i][j-1].first = true;
                next.push(i*w+j-1);
                visited1.insert(i*w+j-1);
            }
            next.pop();
        }
    }
    void bfs2(vector<vector<int>>& matrix, queue<int>& next){
        while (!next.empty()){
            int i = next.front()/w, j = next.front()%w;
            if (i < h-1 && visited2.count((i+1)*w+j) == 0 && matrix[i][j] <= matrix[i+1][j]){
                reached[i+1][j].second = true;
                next.push((i+1)*w+j);
                visited2.insert((i+1)*w+j);
            }
            if (j < w-1 && visited2.count(i*w+j+1) == 0 && matrix[i][j] <= matrix[i][j+1]){
                reached[i][j+1].second = true;
                next.push(i*w+j+1);
                visited2.insert(i*w+j+1);
            }
            if (i > 0 && visited2.count((i-1)*w+j) == 0 && matrix[i][j] <= matrix[i-1][j]){
                reached[i-1][j].second = true;
                next.push((i-1)*w+j);
                visited2.insert((i-1)*w+j);
            }
            if (j > 0 && visited2.count(i*w+j-1) == 0 && matrix[i][j] <= matrix[i][j-1]){
                reached[i][j-1].second = true;
                next.push(i*w+j-1);
                visited2.insert(i*w+j-1);
            }
            next.pop();
        }
    }
};
