// 133. Clone Graph
// DFS，用一个map来建立node和copy的映射，如果没建立过m[node]那就创建一下，不然的话直接返回就好了。
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
        if(!node) return nullptr;
        if(m.find(node)==m.end()){
            m[node]=new UndirectedGraphNode(node->label);
            for(auto item:node->neighbors){
                m[node]->neighbors.push_back(cloneGraph(item));
            }
        }
        return m[node];
    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
};