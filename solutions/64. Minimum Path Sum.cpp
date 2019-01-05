64. Minimum Path Sum
// refined
// beats 23%
// time:O(n*m)
// space: O(n*m)
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