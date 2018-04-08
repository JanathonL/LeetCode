// 64. Minimum Path Sum
// DP Time: O(n^2),  Space: O(n)
// f[i][j] 表示从(0,0)到(i,j)需要最少多少步
// f[i][j] = min(f[i-1][j]+nums[i][j],f[i][j-1]+nums[i][j]);
// 注意一下f[0][j]只能从左向右走， f[i][0]只能从上到下走，f[0][0]=nums[0][0].
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        vector<vector<int>> f(n,vector<int>(m,INT_MAX));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0&&j==0){
                    f[i][j]=grid[0][0];
                }
                else if(i==0){
                    f[i][j]=f[i][j-1]+grid[i][j];
                }
                else if(j==0){
                    f[i][j]=f[i-1][j]+grid[i][j];
                }
                else{
                    f[i][j]=min(f[i-1][j]+grid[i][j],f[i][j-1]+grid[i][j]);
                }
            }
        }
        return f[n-1][m-1];
    }
};