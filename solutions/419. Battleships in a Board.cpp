419. Battleships in a Board
class Solution {
public:

    int countBattleships(vector<vector<char>>& board) {
        
        int rlen = board.size();
        if(rlen==0) return 0;
        int clen = board[0].size();
        if(clen==0) return 0;
        vector<int> parent(rlen*clen,0);
        int cnt = 0;
        for(int i=0;i<rlen;i++){
            for(int j=0;j<clen;j++){
                if((i==0||board[i-1][j]=='.')&&(j==0||board[i][j-1]=='.')&&(board[i][j]=='X')){
                    cnt++;
                }
            }
        }

        
        return cnt;
        
    }
};