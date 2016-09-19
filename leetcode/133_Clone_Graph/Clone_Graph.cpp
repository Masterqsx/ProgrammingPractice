/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        queue<UndirectedGraphNode*> que({node});
        unordered_map<int, UndirectedGraphNode*> check;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        check[node->label] = root;
        while (!que.empty()){
            UndirectedGraphNode* cur = que.front();
            for (auto n : cur->neighbors){
                if (check.count(n->label) == 0) {
                    que.push(n);
                    UndirectedGraphNode* no = new UndirectedGraphNode(n->label);
                    check[n->label] = no;
                }
                check[cur->label]->neighbors.push_back(check[n->label]);
            }
            que.pop();
        }
        return root;
    }
};