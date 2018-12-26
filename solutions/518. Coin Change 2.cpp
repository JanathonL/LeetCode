518. Coin Change 2
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<coins.size()+1;i++){
            dp[i][0] = 1;
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0){
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};
