// 279. Perfect Squares
// dp[i] 表示这个数字所需要的最小完美数的个数
// dp[0]=0
// dp[i] = min(dp[i], dp[i-j*j]+1);
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp.back();
    }
    
            
};
