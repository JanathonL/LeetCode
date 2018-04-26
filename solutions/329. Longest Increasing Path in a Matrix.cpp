// 329. Longest Increasing Path in a Matrix
// 正常的DFS加上memory记忆化搜索，f[i][j]表示从这个点开始的最大长度，初始化为0；
// 这题一直都是超memory，我也是懵逼了，看了一下discuss的代码，和我基本一致，可是他的就能过，经过了很久的观察之后才发现，原来我没有把引用传进去
// 我一开始写的是 dfs（vector<vector<int>> matrix）,这样子造成了递归调用的时候开销非常大，每次都要创建新的matrix进行拷贝，所以会memory超了，
// 最后改成了 vector<vector<int>& matrix就神奇般的通过了。
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row==0) return 0;
        int col = matrix[0].size();
        int longest = 0;
        vector<vector<int>> f(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               longest= max(longest, dfs(matrix,f,i,j,row,col));
            }
        }
        return longest;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& f, int x, int y, int m, int n){
        if (f[x][y] > 0) return f[x][y];
        f[x][y] = 1;
        static int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<4;i++){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= m || nx < 0|| ny >= n || ny < 0) continue;
            if (matrix[nx][ny] < matrix[x][y]){
                f[x][y] = max(f[x][y], dfs(matrix, f, nx, ny, m, n) + 1);
            }
        }
        
        return f[x][y];
    }
};