// 200. Number of Islands
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */
class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int rl = grid.size();
        if(rl==0) return 0;
        int cl = grid[0].size();
        if(cl==0) return 0;
        vector<vector<bool>> visited(rl, vector<bool>(cl, false));
        int cnt = 0;
        for(int i=0;i<rl;i++){
            for(int j=0;j<cl;j++){
                if(!visited[i][j]&& grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir:dirs){
            int nx = x+dir[0];
            int ny = y+dir[1];
            if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[x][y]==grid[nx][ny]&&!visited[nx][ny]){
                dfs(grid,nx,ny,visited);
            }
        }
    }
};