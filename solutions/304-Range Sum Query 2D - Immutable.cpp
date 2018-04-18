// 304. Range Sum Query 2D - Immutable
// 思路跟一维的类似，建立一个累加和矩阵。令状态f[i][j]表示从(0,0)到(i,j)的子矩阵的和，则状态转移方程为
// f[i][j] = f[i-1][j] + rowSum
// 其中 rowSum 是矩阵matrix[i][0]到matrix[i][j]这一行的和。
// 有了f[i][j]， 则
// sumRange(i1,j1,i2,j2) = f[i2][j2] + f[i1-1][j1-1] - f[i1-1][j2]-f[i2][j1-1]
// 将辅助矩阵f[i][j]的行数和列数增1，可以简化对矩阵边界的处理。
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        if(n!=0){
            int m = matrix[0].size();
            sum = vector<vector<int>>(n+1,vector<int>(m+1,0));

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i==1&&j==1){
                        sum[i][j]=matrix[i-1][j-1];
                    }
                    else if(i==1){
                        sum[i][j]=sum[i][j-1]+matrix[i-1][j-1];
                    }
                    else if(j==1){
                        sum[i][j]=sum[i-1][j]+matrix[i-1][j-1];
                    }
                    else{
                        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1];
                    }
                    // cout<<sum[i][j]<<" ";
                }
                // cout<<endl;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]+sum[row1][col1]-sum[row2+1][col1]-sum[row1][col2+1];
    }
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */