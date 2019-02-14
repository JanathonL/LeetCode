200. Number of Islands
// refined
// time: O(NM)
// space: O(1)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(vector<int> dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
    }
};