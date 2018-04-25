// 322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            for(int k=0;k<coins.size();k++){
                if(i-coins[k]>=0&&dp[i-coins[k]]!=INT_MAX){
                    // cout<<i-coins[k]<<" "<<dp[i-coins[k]]<<endl;
                    dp[i]=min(dp[i-coins[k]]+1,dp[i]);
                    // cout<<i<<" "<<dp[i]<<endl;
                }
            }   
        }
        return dp[amount]==INT_MAX? -1:dp[amount];
    }
};