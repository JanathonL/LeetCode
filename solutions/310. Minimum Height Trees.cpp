310. Minimum Height Trees
class Solution {
public:
    class Node{
    public:
        unordered_set<int> neighbors;
        bool is_leaf(){return neighbors.size()==1;}
    };
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<Node> node(n);
        for(int i=0;i<edges.size();i++){
            node[edges[i].first].neighbors.insert(edges[i].second);
            node[edges[i].second].neighbors.insert(edges[i].first);
        }
        vector<int> b1;
        vector<int> b2;
        if(n==1){
            b1.push_back(0);
            return b1;
        }
        if(n==2){
            b1.push_back(0);
            b1.push_back(1);
            return b1;
        }
        for(int i=0;i<n;i++){
            if(node[i].is_leaf()){
                b1.push_back(i);
            }
        }
        while(1){
            for(auto i:b1){
                for(auto item:node[i].neighbors){
                    node[item].neighbors.erase(i);
                    if(node[item].is_leaf()){
                        b2.push_back(item);
                    }
                }
            }
            if(b2.size()==0) return b1;
            b1.clear();
            swap(b1,b2);
        }
    }
};