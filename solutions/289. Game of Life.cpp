289. Game of Life
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int rown=board.size();
        int coln=board[0].size();
        if(rown==0||coln==0) return;
        // cout<<"test0"<<endl;
        vector<vector<int>> tmp(rown, vector<int>(coln));
        
        for(int i =0;i<rown;i++){
            for(int j=0;j<coln;j++){
                // cout<<"i:"<<i<<" j:"<<j<<endl;
                tmp[i][j] = update(board,i,j);
            }
        }
        // cout<<"test1"<<endl;
        board.assign(tmp.begin(),tmp.end());
    }
    int update(vector<vector<int>>& board, int row,int col){
        // cout<<"update0"<<endl;
        int rown=board.size();
        int coln=board[0].size();
        int cnt = 0;
        // cout<<"update1"<<endl;
        for(int i =-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0) continue;
                if(!(row+i>=0&&row+i<rown)||!(col+j>=0&&col+j<coln)) continue;
                if(board[row+i][col+j]==1) cnt++;
            }
        }
        // cout<<cnt<<endl;
        if(board[row][col]==1){
            if(cnt<2) return 0;
            else if(cnt==2 || cnt==3) return 1;
            else{
                return 0;
            }
        }
        else{
            if(cnt==3) return 1;
            else return 0;
        }
    }
};