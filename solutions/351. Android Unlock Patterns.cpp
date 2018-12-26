351. Android Unlock Patterns
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        std::vector<std::vector<int> > jump(10,vector<int>(10,0));
        jump[1][3]=jump[3][1]=2;
        jump[1][7]=jump[7][1]=4;
        jump[3][9]=jump[9][3]=6;
        jump[7][9]=jump[9][7]=8;
        jump[1][9]=jump[9][1]=5;
        jump[2][8]=jump[8][2]=5;
        jump[3][7]=jump[7][3]=5;
        jump[4][6]=jump[6][4]=5;
        vector<bool> visited(10,0);
        int res = 0;
        res += dfs(jump,m,n,1,visited,0,1)*4;
        res += dfs(jump,m,n,1,visited,0,2)*4;
        res += dfs(jump,m,n,1,visited,0,5);
        return res;
    }
    int dfs(vector<vector<int>>& jump, int m, int n, int len, vector<bool>& visited, int res, int num){
        if(len>=m) res++;
        len++;
        if(len>n) return res;
        visited[num]=true;
        for(int i=1;i<=9;i++){
            int j = jump[num][i];
            if(!visited[i]&&(j==0 || visited[j])){
                res = dfs(jump,m,n,len,visited,res,i);
            }
        }
        visited[num]=false;
        return res;
    }
};