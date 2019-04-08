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


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> cache;
    Node* cloneGraph(Node* node) {
        if(cache.count(node)){
            return cache[node];
        }
        int val = node->val;
        vector<Node*> nei = node->neighbors;
        Node* new_node = new Node(val, nei);
        cache[node] = new_node;
        for(int i=0;i<nei.size();i++){
            new_node->neighbors[i] = cloneGraph(nei[i]);
        }
        return new_node;
    }
};