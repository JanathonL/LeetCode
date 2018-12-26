// 36. Valid Sudoku
/*
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};




class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res=true;
        res = res&&checkRow(board);
        // cout<<1<<endl;
        res = res&&checkCol(board);
        // cout<<2<<endl;
        
        res = res&&checkGrid(board);
        // cout<<1<<endl;
        
        return res;
    }
    bool checkRow(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            vector<bool> visited(board[0].size()+1,false); 
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                if(visited[num]) return false;
                visited[num] = true;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board){
        for(int j=0;j<board[0].size();j++){
            vector<bool> visited(board[0].size()+1,false); 
            for(int i=0;i<board.size();i++){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                if(visited[num]) return false;
                visited[num] = true;
            }
        }
        return true;
    }
    bool checkGrid(vector<vector<char>>& board){
        int cx = 1;
        int cy = 1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                // cout<<cx+i*3<<" "<<cy+j*3<<endl;
                if(!check(board, cx+i*3 , cy+j*3)) return false;
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& board,int x,int y){
        vector<bool> visited(10,false);
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(board[i+x][j+y]=='.') continue;
                int num = board[i+x][j+y] - '0';
                
                if(visited[num]) return false;
                visited[num] = true;
            }
        }
        return true;
    }
};