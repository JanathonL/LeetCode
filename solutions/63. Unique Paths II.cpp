63. Unique Paths II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1) return 0;
        vector<int> f(n,0);
        f[0]=1;
        for(int i =0;i<m;i++){
            f[0]= f[0]==0? 0 : (obstacleGrid[i][0]? 0:1);
            for(int j =1;j<n;j++){
                f[j] = obstacleGrid[i][j]? 0: (f[j]+f[j-1]);
            }
        }
        return f[n-1];
    }
    

};
// // Unique Paths II
// // 深搜 + 缓存，即备忘录法
// class Solution {
// public:
//     int uniquePathsWithObstacles(const vector<vector<int> >& obstacleGrid) {
//         const int m = obstacleGrid.size();
//         const int n = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

//         f = vector<vector<int> >(m, vector<int>(n, 0));
//         f[0][0] = obstacleGrid[0][0] ? 0 : 1;
//         return dfs(obstacleGrid, m - 1, n - 1);
//     }
// private:
//     vector<vector<int> > f;  // 缓存

//     // @return 从 (0, 0) 到 (x, y) 的路径总数
//     int dfs(const vector<vector<int> >& obstacleGrid,
//             int x, int y) {
//         if (x < 0 || y < 0) return 0; // 数据非法，终止条件

//         // (x,y)是障碍
//         if (obstacleGrid[x][y]) return 0;

//         if (x == 0 and y == 0) return f[0][0]; // 回到起点，收敛条件

//         if (f[x][y] > 0) {
//             return f[x][y];
//         } else {
//             return f[x][y] = dfs(obstacleGrid, x - 1, y) + 
//                 dfs(obstacleGrid, x, y - 1);
//         }
//     }
// };
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         if(m==0) return 0;
//         int n=obstacleGrid[0].size();
//         if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1) return 0;
//         f=vector<vector<int>>(m,vector<int>(n,0));
//         f[0][0]=1;
//         return dfs(m-1,n-1,obstacleGrid);
//     }
//     int dfs(int x,int y,vector<vector<int>>& obstacleGrid){
//         if(x<0||y<0) return 0;
//         if(x==0&&y==0) return f[x][y];
//         if(obstacleGrid[x][y]==1) return 0;
//         if(f[x][y]>0){
//             return f[x][y];
//         }
//         else{
//             f[x][y]=dfs(x-1,y,obstacleGrid)+dfs(x,y-1,obstacleGrid);
//             return f[x][y];
//         }
//     }
// private:
//     int cnt;
//     vector<vector<int>> f;
// };