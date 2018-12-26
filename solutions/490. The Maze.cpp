490. The Maze
class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> dirs;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rowl = maze.size();
        int coll = maze[0].size();
        for(int i =0;i<rowl;i++){
            visited.push_back(vector<bool>(coll, false));
        }
        dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        return helper(maze, start, destination);
    }
    bool helper(vector<vector<int>>& maze, vector<int> start, vector<int> destination){
        int rowl = maze.size();
        int coll = maze[0].size();
        bool result = false;
        visited[start[0]][start[1]]=true;
        for(auto dir:dirs){
            
            int newx = dir[0]+start[0];
            int newy = dir[1]+start[1];
            
            while(newx>=0 && newx<rowl && newy>=0 && newy<coll && maze[newx][newy]!=1){
                newx = dir[0]+newx;
                newy = dir[1]+newy;
            }
            newx -= dir[0];
            newy -= dir[1];
            if(newx==destination[0] && newy==destination[1]){
                result = true;
                break;
            }
            if(visited[newx][newy]==1 || newx == start[0] && newy == start[1]){
                continue;
            }
            vector<int> newstart = {newx, newy};
            
            result = result || helper(maze, newstart, destination);
            if(true==result){
                break;
            }
        }
        return result;
    }
};