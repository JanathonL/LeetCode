174. Dungeon Game
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if(n==0) return 1;
        int m = dungeon[0].size();
        vector<vector<int>> f(n,vector<int>(m,1));
        for(int i =n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(i==n-1&&j==m-1){
                    f[i][j]=max(1,1-dungeon[i][j]);
                }
                else if(i==n-1){
                    f[i][j]=max(f[i][j],f[i][j+1]-dungeon[i][j]);
                }
                else if(j==m-1){
                    f[i][j]=max(f[i][j],f[i+1][j]-dungeon[i][j]);
                }
                else{
                    f[i][j]=max(f[i][j],min(f[i+1][j]-dungeon[i][j],f[i][j+1]-dungeon[i][j]));
                }
                
            }
        }        
        return f[0][0];
    }
};