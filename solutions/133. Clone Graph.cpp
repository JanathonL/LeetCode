133. Clone Graph
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
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) {
            return NULL;
        }
        if(dict.count(node)){
            return dict[node];
        }
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        dict[node] = new_node; 
        for(int i=0;i<node->neighbors.size();i++){
            new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
            
        }
        return new_node;
    }
};