417. Pacific Atlantic Water Flow
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        if(matrix.size() ==0 || matrix[0].size()==0) return res;
        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            dfs(matrix,-1,visited,i,0,res);
        }
        for(int j=0;j<matrix[0].size();j++){
            dfs(matrix,-1,visited,0,j,res);
        }
        for(int i=0;i<matrix.size();i++){
            dfs(matrix,1,visited,i,matrix[0].size()-1,res);
        }
        for(int j=0;j<matrix[0].size();j++){
            dfs(matrix,1,visited,matrix.size()-1,j,res);
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix, int label, vector<vector<int>>& visited, int x, int y, vector<pair<int,int>>& res){
        if(visited[x][y]!=0 && visited[x][y]!=label){
            visited[x][y]+=label;
            res.push_back(make_pair(x,y));
        }
        else if(visited[x][y]==0){
            visited[x][y]+=label;
        }
        else{
            return;
        }
        int rl = matrix.size();
        int cl = matrix[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir:dirs){
            int newx = x+dir[0];
            int newy = y+dir[1];
            if(newx<0 || newx>=rl || newy<0 || newy>=cl || matrix[x][y] > matrix[newx][newy])
                continue;
            dfs(matrix,label,visited,newx,newy,res);
        }
    }
};