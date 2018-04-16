// 53. Maximum Subarray
// (1)	直接online做，如果遇到当前累加的sum<0就重置sum=0,时刻更新maxsum就可以了。 Time: O(n),  Space: O(1)
// (2)	DP的思想，f[i]是以nums[i]结尾最大子串的值。Time: O(n),  Space: O(1)
// 转移方程是：   
// f[j] = max(f[j-1] + s[j] , s[j]),  1<= j <= n

