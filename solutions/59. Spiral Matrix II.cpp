// 59. Spiral Matrix II
// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// Example:

// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rh=n, ch=n;
        int rl = 0, cl = 0;
        int index = 1;
        vector<vector<int>> m(n,vector<int>(n,0));
        while(cl<=ch && rl<= rh){
            for(int j=cl;j<ch;j++){
                m[rl][j]=index++;
            }
            rl++;
            for(int i=rl;i<rh;i++){
                m[i][ch-1]=index++;
            }
            ch--;
            for(int j=ch-1;j>=cl;j--){
                m[rh-1][j]=index++;
            }
            rh--;
            for(int i=rh-1;i>=rl;i--){
                m[i][cl] = index++;
            }
            cl++;
        }
        return m;
    }
};