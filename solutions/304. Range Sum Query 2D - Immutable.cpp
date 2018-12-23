304. Range Sum Query 2D - Immutable
class NumMatrix {
public:
    /*
    18 min 
    3 wrongs
    
    space: O(nm)
    */
    // time: O(nm)
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return;
        int row = matrix.size();
        int col = matrix[0].size();
        sum.resize(row+1, vector<int>(col+1, 0));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] +sum[i][j-1] -sum[i-1][j-1];
            }
        }
    }
    // time: O(1)
    int sumRegion(int row1, int col1, int row2, int col2) { 
        row1 += 1;
        col1 += 1;
        row2 += 1;
        col2 += 1;
        //注意这里 [row2, col1-1] , [row1-1][col2], [row1-1][col1-1] 
        // 画图理解一下
        int res = sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];  

        return res;
    }
vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */