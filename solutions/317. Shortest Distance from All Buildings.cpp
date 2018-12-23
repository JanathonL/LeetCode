317. Shortest Distance from All Buildings
class Solution {
public:
    /*
    先找到house总数 num
    从house开始搜
    一个二维数组是 reached, 记录有几个house能到达这个地方
    另一个二维数组是 dist, 记录这几个house到达这个点的距离之和
    每次用BFS做
    20 min 
    2 wrongs
    time: O(k*m*n)  k is the number of houses
    space: O(m*n)
    */
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(row, vector<int>(col, 0));
        vector<vector<int>> reached(row, vector<int>(col, 0));
        // cout<<row<<" "<<col<<endl;
        int total_house = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    // cout<<i<<" "<<j<<endl;
                    total_house++;
                    // BFS
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    visited[i][j] = true;
                    int step = 0;
                    while(!que.empty()){
                        step++;
                        int size = que.size();
                        for(int k=0;k<size;k++){
                            pair<int,int> cur = que.front();
                            que.pop();
                            int r = cur.first;
                            int c = cur.second;
                            for(auto dir:dirs){
                                int x = r+dir[0];
                                int y = c+dir[1];
                                if(x>=0 && x<row && y>=0 && y<col && !visited[x][y] && grid[x][y]==0){
                                    visited[x][y] = true;
                                    reached[x][y]++;
                                    // cout<<x<<" "<<y<<endl;
                                    dist[x][y] += step;
                                    que.push({x,y});
                                }
                            }
                        }
                    }
                }
            }
        }
        int min_dist = INT_MAX;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(reached[i][j]==total_house){
                    // cout<<i<<" "<<j<<endl;
                    min_dist = min(min_dist, dist[i][j]);
                }
            }
        }
        return min_dist==INT_MAX? -1:min_dist;
    }
};