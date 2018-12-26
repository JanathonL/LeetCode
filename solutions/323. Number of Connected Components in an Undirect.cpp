323. Number of Connected Components in an Undirected Graph
class Solution {
public:
    vector<int> parent;
    int find(int x){
        while(x != parent[x]){
            x = parent[x];
            parent[x] = parent[parent[x]];
            
        }
        return x;
        
    }
    void connect(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return ;
        parent[x]= y;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        for(int i=0;i<edges.size();i++){
            connect(edges[i].first, edges[i].second);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};