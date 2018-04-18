// 72. Edit Distance
// DP time: O(n*m)  Space: O(m*n)
// d[i][j]表示 word[0…i-1] -> word[0…j-1]的最少步数
// 1.	dp[i][0] = i;
// 2.	dp[0][j] = j;
// 3.	dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
// 4.	dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.

class Solution {
public:
    int minDistance(string word1, string word2) {
        // cout<<"test"<<endl;
        int n = word1.size();
        int m = word2.size();
        if(n==0||m==0) {
            if(n==0) return m;
            else return n;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j =1;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]= min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                }
            }
        }
        return dp[n][m];
    }
};