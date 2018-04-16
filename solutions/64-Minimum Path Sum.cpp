// 64. Minimum Path Sum
// DP Time: O(n^2),  Space: O(n)
// f[i][j] 表示从(0,0)到(i,j)需要最少多少步
// f[i][j] = min(f[i-1][j]+nums[i][j],f[i][j-1]+nums[i][j]);
// 注意一下f[0][j]只能从左向右走， f[i][0]只能从上到下走，f[0][0]=nums[0][0].
