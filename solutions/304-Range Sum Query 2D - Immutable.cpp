// 304. Range Sum Query 2D - Immutable
// 思路跟一维的类似，建立一个累加和矩阵。令状态f[i][j]表示从(0,0)到(i,j)的子矩阵的和，则状态转移方程为
// f[i][j] = f[i-1][j] + rowSum
// 其中 rowSum 是矩阵matrix[i][0]到matrix[i][j]这一行的和。
// 有了f[i][j]， 则
// sumRange(i1,j1,i2,j2) = f[i2][j2] + f[i1-1][j1-1] - f[i1-1][j2]-f[i2][j1-1]
// 将辅助矩阵f[i][j]的行数和列数增1，可以简化对矩阵边界的处理。
