// 72. Edit Distance
// DP time: O(n*m)  Space: O(m*n)
// d[i][j]表示 word[0…i-1] -> word[0…j-1]的最少步数
// 1.	dp[i][0] = i;
// 2.	dp[0][j] = j;
// 3.	dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
// 4.	dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.

