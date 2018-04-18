// 174. Dungeon Game
// 这题和走迷宫的思路很像
// 不过由于右下角是已知的所以是从右下角向左上角遍历
// f[i][j]表示到这个格子，需要的最少血量
// f[i][j]=max(1, min(f[i+1][j]-d[i][j],f[i][j+1]-d[i][j]));
// 注意首先要选一个两个方向上较小的那个，然后这个值要与1相比选大的那个，
// 因为如果血量算出来小于零，说明这个格子本身不会让你扣血，只需要1就可以。
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