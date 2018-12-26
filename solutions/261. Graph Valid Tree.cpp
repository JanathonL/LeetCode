261. Graph Valid Tree
class Solution {
public:
    /*
    n node -> n-1 edges
    no circle -> topo sort
    if ( not parent and visited) return false
    size != n return false
    17 min 
    1 wrong
    不熟练！！！
    time: O(VE)
    space: O(VE)
    */
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        queue<pair<int,int>> que;
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> neighbs;
        for(int i=0;i<edges.size(); i++){
            int first = edges[i].first;
            int second = edges[i].second;
            neighbs[first].push_back(second);
            neighbs[second].push_back(first);
        }
        visited[0] = true;
        int cnt = 0;
        que.push({0,0});
        while(!que.empty()){
            pair<int,int> cur = que.front();  // que没有top!!!!
            que.pop();
            cnt++;
            for(int neighb : neighbs[cur.first]){
                if(visited[neighb]){
                    if(neighb!=cur.second){
                        return false;
                    }
                } else {
                    visited[neighb] = true;
                    que.push({neighb, cur.first});
                }
            }
        }
        return cnt==n;
    }
};