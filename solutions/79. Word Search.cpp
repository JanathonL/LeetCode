79. Word Search
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        int rl = board.size();
        if(rl==0){
            return false;
        }
        int cl = board[0].size();
        
        if(cl==0) return false;
        bool res = false;
        for(int i=0;i<rl;i++){
            for(int j=0;j<cl;j++){
                if(board[i][j]==word[0]){
                    res = res || dfs(board,i,j, 1,word);
                    if(res) return true;
                }
            }
        }
        return res;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, int cnt, string word){
        // cout<<str<<endl;
        if(cnt==word.size()){
            return true;
        }
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        char t = board[x][y];
        board[x][y]='\0';
        bool res = false;
        for(auto dir:dirs){
            int nx = x+dir[0];
            int ny = y+dir[1];
            if(check(nx,ny,board)&&board[nx][ny]==word[cnt]){
                res = res || dfs(board,nx,ny,cnt+1,word);
                if(res) return true;
            }
        }
        board[x][y]=t;
        return res;
    }
    bool check(int x, int y, vector<vector<char>> board){
        if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()){
            return true;
        }
        else{
            return false;
        }
    }
};

// refined
// beat 18.9%
// time: O(n*m*(n*m))
// space: O(1)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return true;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    
                    if(backtrack(board,word,i,j,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>> &board, string word, int row, int col, int ind){
        char old = board[row][col];
        board[row][col] = '.';        
        if(ind==word.size()){
            return true;
        }
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(vector<int> dir:dirs){
            int x = row + dir[0];
            int y = col + dir[1];
            if(x>=0&&x<board.size() && y>=0 && y<board[0].size() && board[x][y]==word[ind]){
                if(backtrack(board,word,x,y,ind+1)){
                    return true;
                }
            }
        }
        board[row][col] = old;
        return false;
    }
};