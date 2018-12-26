361. Bomb Enemy
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rlen = grid.size();
        if(rlen ==0 ) return 0;
        int clen = grid[0].size();
        if(clen == 0) return 0;
        vector<vector<int>> v1(rlen, vector<int>(clen, 0));
        vector<vector<int>> v2(rlen, vector<int>(clen, 0));
        vector<vector<int>> v3(rlen, vector<int>(clen, 0));
        vector<vector<int>> v4(rlen, vector<int>(clen, 0));
        int res=0;
        for(int i=0;i<rlen;i++){
            int cnt = 0;
            for(int j=0;j<clen;j++){
                int t = (j == 0 || grid[i][j] == 'W') ? 0 : v1[i][j - 1];
                v1[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            cnt = 0;
            for(int j=clen-1;j>=0;j--){
               int t = (j == clen - 1 || grid[i][j] == 'W') ? 0 : v2[i][j + 1];
                v2[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int j = 0; j < clen; ++j) {
            for (int i = 0; i < rlen; ++i) {
                int t = (i == 0 || grid[i][j] == 'W') ? 0 : v3[i - 1][j];
                v3[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            for (int i = rlen - 1; i >= 0; --i) {
                int t = (i == rlen - 1 || grid[i][j] == 'W') ? 0 : v4[i + 1][j];
                v4[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for(int i=0;i<rlen;i++){
            for(int j=0;j<clen;j++){
                if(grid[i][j]=='0')
                    res = max(res, v1[i][j]+v2[i][j]+v3[i][j]+v4[i][j]);
            }
        }
        return res;
    }
};