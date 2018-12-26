695. Max Area of Island
class Solution {
public:
    int maxcnt;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rlen = grid.size();
        if(rlen==0) return 0;
        int clen = grid[0].size();
        if(clen==0) return 0;
        maxcnt = 0;
        int cnt = 0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(rlen, vector<int>(clen,0));
        for(int i=0;i<rlen;i++){
            for(int j=0;j<clen;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    cnt=1;
                    helper(grid,i,j,cnt,visited,dir);
                }
                    
                    
            }
        }
        return maxcnt;
    }
    void helper(vector<vector<int>>& grid, int x, int y, int& cnt, vector<vector<int>>& visited, vector<vector<int>> dir){
        visited[x][y]=1;
        for(int i=0;i<dir.size();i++){
            int newx = x+dir[i][0];
            int newy = y+dir[i][1];
            if(newx>=0 && newy >=0 && newx< grid.size() && newy < grid[0].size() && visited[newx][newy]==0 && grid[newx][newy]==1){
                cnt++;
                helper(grid,newx,newy,cnt,visited, dir);
            }
        }
        maxcnt = max(cnt, maxcnt);
    }
};