54. Spiral Matrix
/*
  ->
 |  |
  <-
row_lo, row_hi
col_lo, col_hi
3 wrong
20 min
time: O(n*m)
space: O(n*m)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0){
            return vector<int>();
        }
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int ind_dir = 0;
        int cur_r = 0;
        int cur_c = -1;
        int n = matrix.size();
        int m = matrix[0].size();
        // vertical step init with col size and horizontal step init with row size -1
        vector<int> steps = {m, n-1};  
        vector<int> res;
        while(steps[ind_dir%2]){
            for(int i=0;i<steps[ind_dir%2];i++){
                cur_r += dirs[ind_dir][0];
                cur_c += dirs[ind_dir][1];
                // cout<<ind_dir<<" "<<cur_r<<" "<<cur_c<<endl;
                res.push_back(matrix[cur_r][cur_c]);
            }
            steps[ind_dir%2]--;
            ind_dir = (ind_dir+1)%4;
        }
        return res;
    }
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     vector<int> res;
    //     if(matrix.size()==0 || matrix[0].size()==0) {
    //         return res;
    //     }
    //     // perform simulating
    //     int row_lo = 0;
    //     int row_hi = matrix.size()-1;
    //     int col_lo = 0;
    //     int col_hi = matrix[0].size()-1;
    //     while(row_lo<=row_hi &&col_lo<=col_hi){
    //         // right
    //         for(int j = col_lo;j<=col_hi;j++){
    //             res.push_back(matrix[row_lo][j]);
    //         }
    //         row_lo++;
    //         // left
    //         for(int i = row_lo;i<=row_hi;i++){
    //             res.push_back(matrix[i][col_hi]);
    //         }
    //         col_hi--;
    //         if(row_lo<=row_hi){
    //             for(int j=col_hi;j>=col_lo;j--){
    //                 res.push_back(matrix[row_hi][j]);
    //             }
    //         }
    //         row_hi--;
    //         if(col_lo<=col_hi){
    //             for(int i=row_hi;i>=row_lo;i--){
    //                 res.push_back(matrix[i][col_lo]);
    //             }
    //         }
    //         col_lo++;
    //     }
    //     return res;
    // }
};