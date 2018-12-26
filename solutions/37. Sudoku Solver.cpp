// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.
class Solution {
public:
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    
    void solveSudoku(vector<vector<char>>& board) {
        int left = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') {
                    left++;
                }
                else{
                    int num = board[i][j] - '0', k = i / 3 * 3 + j / 3;
                    used1[i][num-1] = used2[j][num-1] = used3[k][num-1] = 1;
                }
            }
        }
        dfs(board,left);
    }
    bool dfs(vector<vector<char>>& board, int left){
        // printBoard(board);
        if(left==0){
            return true;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.') continue;
                for(int num=1;num<=9;num++){
                    int k = i / 3 * 3 + j / 3;
                    board[i][j] = num+'0';
                    if(used1[i][num-1] || used2[j][num-1]||used3[k][num-1]){
                        board[i][j] = '.';
                        continue;
                    }
                    else{
                        used1[i][num-1] = used2[j][num-1] = used3[k][num-1] = 1;
                        if(dfs(board,left-1)) {
                            return true;
                        }
                    }
                    board[i][j] = '.';
                    used1[i][num-1] = used2[j][num-1] = used3[k][num-1] = 0;
                }
                return false;
            }
        }
        return false;
    }
    void printBoard(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<(board[i][j])<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};