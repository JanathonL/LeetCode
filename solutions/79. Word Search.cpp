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