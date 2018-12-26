286. Walls and Gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        if(rooms.size()==0 || rooms[0].size()==0) return;
        int rlen = rooms.size();
        int clen = rooms[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> visited(rlen, vector<int>(clen, 0));
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j]==0){
                    helper(rooms,dirs,i,j,0);
                }
            }
        }
        
    }
    void helper(vector<vector<int>>& rooms, vector<vector<int>> dirs, int r, int c, 
            int level){
        if(rooms[r][c] == 2147483647){
            rooms[r][c] = level;
        }
        else if(rooms[r][c]==-1){
            return;
        }
        else if(level <= rooms[r][c]){
            rooms[r][c] = min(rooms[r][c], level);
        }
        else{
            return;
        }
        
        for(auto dir: dirs){
            int x = r+dir[0];
            int y = c+dir[1];
            if(x>=0 && x<rooms.size() && y>=0 && y<rooms[0].size() 
                    && rooms[x][y]!=-1 && level < rooms[x][y]){
                helper(rooms, dirs, x, y, level+1);
            }
        }
    }
};