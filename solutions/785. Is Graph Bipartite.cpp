785. Is Graph Bipartite?
class Solution {
public:
    /*
    dfs with color
    8 min
    bug free
    time: O(VE)
    space: O(E)  depth is the call times of dfs
    */
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& colors, int color){
        colors[cur] = color;
        bool res = true;
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(colors[next]==-1){
                res = dfs(graph, next, colors, !color);
                if(res == false){
                    return false;
                }
            } else if(colors[next]==colors[cur]){
                return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // check empty
        if(graph.size()==0){
            return true;
        }
        int n = graph.size();
        vector<int> colors(n,-1);
        bool res = true;
        for(int i=0;i<colors.size();i++){
            if(colors[i]==-1){
                res = dfs(graph, i, colors, 1);
                if(res == false){
                    return false;
                }
            }
        }
        return true;
    }
};