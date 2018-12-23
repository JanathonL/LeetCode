class Solution {
public:
    /*
    DFS + Mem
    start from (i,j), search
    Mem[i][j] means max length from (i,j) to the end
    14 min 
    1 wrong
    time: O(n*m)
    space: O(n*m)
    */
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0){
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int max_len = INT_MIN;
        vector<vector<int>> mem(row, vector<int>(col, -1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dfs(matrix, mem, i, j, max_len, 1);
            }
        }
        return max_len;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& mem, int i, int j, int& max_len, int cur){
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        int res = 0;
        for(auto dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            if(x>=0 && x<row && y>=0 && y<col && matrix[x][y]>matrix[i][j]){
                int temp = dfs(matrix, mem, x, y, max_len, cur+1);
                res = max(res, temp+1);
            }
        }
        max_len = max(max_len, cur+res);
        mem[i][j] = res;
        return res;
    }
};