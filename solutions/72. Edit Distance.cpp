// 72. Edit Distance
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */
class Solution {
public:
    int ans = INT_MAX;
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,INT_MAX));
        dp[word1.size()][word2.size()] = 0;
        int cnt = 0;
        for(int i=word1.size()-1;i>=0;i--){
            dp[i][word2.size()] = ++cnt;
        }
        cnt = 0;
        for(int j=word2.size()-1;j>=0;j--){
            dp[word1.size()][j] = ++cnt;
        }
        for(int i=word1.size()-1;i>=0;i--){
            for(int j=word2.size()-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))+1;
                }
            }
        }
        return dp[0][0];    
    }
};